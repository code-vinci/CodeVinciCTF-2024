#include "LightBird.h"


void init_HTTP_Server( HTTP_Server* server, unsigned short port )
{
    server->port = port;
    server->socket = socket(AF_INET, SOCK_STREAM, 0);
    if ( server->socket == -1 ) {
        printf("Could not create socket;\n");
        exit(1);
    }

	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(port);
	server_address.sin_addr.s_addr = INADDR_ANY;

	if ( bind(server->socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0 ) {
        printf("Error during bind socket;\n");
        exit(1);
    }

    server->routes = init_hash_table( HASHTABLESIZE );
}

void close_HTTP_Server( HTTP_Server* server )
{
    server->routes = del_hash_table( server->routes );
    close( server->socket );
    server->socket = 0;
    server->port = 0;
}


void listen_HTTP_Server( HTTP_Server* server )
{
    char* buffer = malloc( 1048576 );   // 1MB
    listen(server->socket, 10);
    
    for ( ; ; ) {
        Request req;
        struct sockaddr_in client;
        int addrlen = sizeof(client);
        
        int client_sock = accept( server->socket, (struct sockaddr*)&client, (socklen_t*)&addrlen );

        int n_read = recv( client_sock, buffer, 1048574, 0);
        buffer[n_read] = '\0';

        sscanf( buffer, "%6s %100s %100s\n", req.method, req.route, req.version);

        char* ret = search( server->routes, req.route );
        int content_size = 0;

        if ( ret != NULL ) {
            FILE* file = fopen( ret , "r");
            if ( file != NULL ) {
                content_size = fread( buffer, sizeof(char), 1048574, file );
                buffer[content_size] = '\0';
                content_size++;
                fclose(file);
            }
        }

        send( client_sock, buffer, content_size, 0 );

        close( client_sock );
    }
}

unsigned int hash( const char* key, int mod )
{
    unsigned int hash_value = 0;
    for ( int i = 0; key[i] ; i++ ) {
        hash_value = 31 * hash_value + key[i];
    }
    return hash_value % mod;
}

HashTable init_hash_table( int size )
{
    HashTable hash_table;
    hash_table.table = (KeyValuePair**)malloc(sizeof(KeyValuePair*)*size);
    hash_table.size = size;
    for ( int i = 0; i < hash_table.size ; i++ ) {
        hash_table.table[i] = NULL;
    }
    return hash_table;
}

HashTable del_hash_table( HashTable hash_table )
{
    for ( int i = 0 ; i < hash_table.size ; i++ ) {
        free( hash_table.table[i] );
    }
    free( hash_table.table );
    return (HashTable){.table=NULL,.size=0};
}

int insert( HashTable hash_table, char* key, char* value )
{
    int count_iterations = 0;
    unsigned int index = hash( key, hash_table.size );

    while ( hash_table.table[index] != NULL && count_iterations < hash_table.size ) {
        index = (index + 1) % hash_table.size;
        count_iterations++;
    }

    if ( hash_table.size <= count_iterations )     return -1;

    KeyValuePair* pair = (KeyValuePair*)malloc(sizeof(KeyValuePair));
    pair->key = key;
    pair->value = value;
    hash_table.table[index] = pair;

    return index;
}

char* search( HashTable hash_table, const char* key )
{
    int count_iterations = 0;
    unsigned int index = hash( key, hash_table.size );

    while ( hash_table.table[index] != NULL && count_iterations < hash_table.size ) {
        if ( strcompare( hash_table.table[index]->key, key ) == 0 ) {
            return hash_table.table[index]->value;
        }
        index = (index + 1) % hash_table.size;
        count_iterations++;
    }

    return NULL;
}

int strcompare( const char* a, const char* b )
{
    for ( int i = 0 ; a[i] ; i++ ) {
        int variant = a[i] - b[i];
        if ( variant != 0 )     return variant;
    }
    return 0;
}
