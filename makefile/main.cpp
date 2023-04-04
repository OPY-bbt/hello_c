// g++.exe -fdiagnostics-color=always -g ./main.cpp -o ./main.exe && ./main.exe
// gcc main.cpp -o main.exe -lstdc++

#include <iostream>
#include <cstring>

#include <windows.h>
#include <windns.h>
#include <stdio.h>

#include "function.h"

class Animal {
  public:
    void say();
};

void Animal::say() {
  std::cout << "Animal say Hello World! \n";
};

class Dog: public Animal {
  public:
    void say() {
      std::cout << "Dog say Hello World! \n";
    }
};

int main() {
  Animal myAnimal;
  myAnimal.say();

  Dog myDog;
  myDog.say();

  func();

  PDNS_RECORD pDnsRecord; //Pointer to DNS_RECORD structure
  DNS_STATUS status;      //Return value of DnsQuery function
  IP4_ARRAY addrArray;    //Additional parameters for DnsQuery
  const wchar_t *pName = L"www.google.com"; //DNS name to query

  //Initialize the DNS server IP address array
  addrArray.AddrCount = 1;
  addrArray.AddrArray[0] = inet_addr("8.8.8.8"); //Google's DNS server

  //Call DnsQuery to get the A record of www.google.com
  status = DnsQuery_W(pName, DNS_TYPE_A, DNS_QUERY_BYPASS_CACHE | DNS_QUERY_NO_HOSTS_FILE | DNS_QUERY_NO_NETBT | DNS_QUERY_NO_LOCAL_NAME, NULL, &pDnsRecord, NULL);

  if (status == ERROR_SUCCESS)
  {
      printf("DNS query succeeded.\n");
      printf("The A record of %ls is %s\n", pName, inet_ntoa(*(struct in_addr *)&(pDnsRecord->Data.A.IpAddress)));
      DnsRecordListFree(pDnsRecord, DnsFreeRecordList); //Free memory allocated for DNS records
  }
  else
  {
      printf("DNS query failed with error %d\n", status);
  }

};