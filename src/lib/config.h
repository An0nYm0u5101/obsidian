#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "utils.h"
#include "peer.h"
#include <stdint.h>
#include "network.h"
#include "filter.h"


#define DEXPD_CONFIG_FILE "/etc/obsidian.conf"

#define MAX_OPT_STR_LEN STR_BIG_S


typedef struct dexpd_config {
   peer *peers;
   int nb_peers;
   void **filters;

   char data_dir[MAX_OPT_STR_LEN];
   char metadata_dir[MAX_OPT_STR_LEN];
   char tmp_dir[MAX_OPT_STR_LEN];
   char listening_addr[MAX_OPT_STR_LEN];
   int listening_port;

   char node_name[MAX_OPT_STR_LEN];
   char node_descr[MAX_OPT_STR_LEN*2];
   char node_location[STR_SMALL_S];
   int keepalive_timeout;

   uint8_t log_level;
   uint8_t log_stdout;
   char log_file[MAX_OPT_STR_LEN];
   
   uint8_t use_ipv6;
   char ipv6_listening_addr[MAX_OPT_STR_LEN];   

   uint8_t use_tls;
   //char tls_cli_cert[MAX_OPT_STR_LEN];
   char tls_server_ca[MAX_OPT_STR_LEN];
   char tls_server_cert[MAX_OPT_STR_LEN];
   char tls_server_dh[MAX_OPT_STR_LEN];

   SSL_CTX *ctx;
   ruleset rs;
   uint8_t pub;
   
} dexpd_config;


//definition of global variables to handle config 
//(to avoid passing them by reference each time we need them)
int nb_cat;
dexpd_config conf0;
//

int init_config();

#endif




