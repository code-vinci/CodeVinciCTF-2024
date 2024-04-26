#include "./lib/LightBird.c"


int main( int argc, char** argv )
{
    HTTP_Server server;
    init_HTTP_Server( &server, 80 );


    insert( server.routes,  "/flag",        "views/bad.html"    );
    insert( server.routes,  "/flag",        "views/flag.txt"    );
    insert( server.routes,  "/favicon.ico", "views/favicon.ico" );
    insert( server.routes,  "/",            "views/index.html"  );
    insert( server.routes,  "/about",       "views/about.html"  );
    

    listen_HTTP_Server( &server );


    close_HTTP_Server( &server );
    return 0;
}
