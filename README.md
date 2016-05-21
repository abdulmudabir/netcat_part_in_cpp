# netcat_part_in_cpp

netcat_part is unix's partial implementation of **nc** i.e. the network 
version of cat.

#### usage
```sh
netcat_part [OPTIONS] dest_ip [file]
-h Print this help screen
-v Verbose output
-m "MSG" Send the message specified 
Warning: if you specify this option, you do not specify a file
-p portSet the port to connect on (dflt: 6767)
-n bytes Number of bytes to send, defaults whole file
-o offset Offset into file to start sending
-l Listen on port instead of connecting and write output to file 
and dest_ip refers to which ip to bind to (dflt: localhost)
```

#### usage examples
```sh
$ ./netcat_part -m "Hello World" localhost
```
#### Test cases for cli arguments to netcat_part
1. Avoid Alphanumeric input where numeric is expected. For options -p, -n, -o  
&nbsp;* Need to use an "all digits input" checker function. Does not take care 
of negative (signed) input  
2. List all kinds of input for "$ ./netcat_part -l" i.e. SERVER mode  
&nbsp;* $ ./netcat_part -l goodServer.name => OK  
&nbsp;* $ ./netcat_part -l goodServer.name outputFile => OK   
&nbsp;* $ ./netcat_part -l goodServer.name -p 4268 outputFile.txt => OK   
&nbsp;* $ ./netcat_part -l => OK  
&nbsp;* $ ./netcat_part -l badServer.name -p 4268 => OK  
3. Check machineName sanity immediately after copying serverName => DONE  
4. Check valid range of port numbers => DONE   
&nbsp;* $ ./netcat_part -p 4268 => OK   
&nbsp;* $ ./netcat_part -p -8067 => OK   
&nbsp;* $ ./netcat_part -p --6985 => OK  
&nbsp;* $ ./netcat_part -p $a6791 => OK   
&nbsp;* $ ./netcat_part -p 426 => OK  
&nbsp;* $ ./netcat_part -p 65597 => OK   
&nbsp;* $ ./netcat_part -p 8453246 => OK  
5. Overflow values input for 'number of bytes', 'file offset' are input as 
extremely large numbers = NOT OK   
6. 
