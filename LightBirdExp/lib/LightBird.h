#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define HASHTABLESIZE 100

typedef struct {
    char* key;
    char* value;
} KeyValuePair;

typedef struct {
    int size;
    KeyValuePair** table;
} HashTable;

typedef struct {
    int socket;
    unsigned short port;
    HashTable routes;
} HTTP_Server;

typedef struct {
    char method[8];
    char route[128];
    char version[128];
} Request;

// Initialize http server
void init_HTTP_Server( HTTP_Server* server, unsigned short port );

// Close and deallocate memory and close de socket
void close_HTTP_Server( HTTP_Server* server );

// Open in a while true listening of request
void listen_HTTP_Server( HTTP_Server* server );

// Simple and fast hash function
unsigned int hash( const char* key, int mod );

// Initialize hash table for store routes
HashTable init_hash_table( int size );

// Used for deallocate all memory usage from dict
HashTable del_hash_table( HashTable hash_table );

// Insert new root to the hash table
int insert( HashTable hash_table, char* key, char* value );

// Research from a key in a HashTable
char* search( HashTable hash_table, const char *key );

// Function to compare two strings
int strcompare( const char* a, const char* b );