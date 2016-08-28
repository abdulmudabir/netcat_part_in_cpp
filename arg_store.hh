#ifndef __ARG_STORE_HH__
#define __ARG_STORE_HH__

#include <getopt.h>
#include <iostream>
#include <cstdlib>

namespace netcat_part
{

void help()
{
   std::cout << "\nnetcat_part [OPTIONS] dest_ip [FILE]\n" 
             << "\t-h\t\tPrint this help screen.\n"
             << "\t-v\t\tVerbose output of netcat_part.\n"
             << "\t-m \"MSG\"\tMessage to be sent.\n"
             << "\t\t\tWarning: If you specify this option, you do not specify a file.\n"
             << "\t-p port\t\tPort to connect to (default: 6767).\n"
             << "\t-n bytes\tNumber of bytes to send (default: whole file).\n"
             << "\t-o offset\tOffset into file to send from.\n"
             << "\t-l\t\tListen on port instead of connecting and write output to file \n"
             << "\tdest_ip\t\tip to bind to (default: localhost).\n\n";
}

struct ArgStore
{
   ArgStore(): verbose(false), message(""), port(6767), 
               num_bytes(0), file_offset(0) {}

   bool verbose;
   std::string message;
   short port;
   int num_bytes;
   int file_offset;
};

class ArgsParser
{
 public:
   ArgsParser(int cnt, char* args[])
   {
      int longindex, opt;
      const struct option longoptions[] = 
      {
         {"help",    no_argument,         0,  'h'},
         {"verbose", no_argument,         0,  'v'},
         {"message", required_argument,   0,  'm'},
         {"port",    required_argument,   0,  'p'},
         {"bytes",   required_argument,   0,  'n'},
         {"offset",  required_argument,   0,  'o'},
         {"listen",  no_argument,         0,  'l'},
         {0,         0,                   0,   0}
      };

      if (cnt < 2)
      {
         std::cout << "Insufficient options specified.\n";
         help();
         exit(EXIT_FAILURE);
      }

      while((opt = getopt_long(cnt, args, "hvm:p:n:o:l", longoptions, &longindex)) != -1)
      {
         switch(opt)
         {
            case 'h': help(); break;
            case 'v': 
            case 'm':
            case 'p':
            case 'n':
            case 'o':
            case 'l':
            default :
               std::cerr << "Unrecognized option!\n";
               help();
               break;
         }
      }
   }
 public:
   static ArgStore m_args;
};

}

#endif
