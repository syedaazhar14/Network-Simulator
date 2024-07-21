#include<bits/stdc++.h>
using namespace std;

//A cyclic redundancy check (CRC) Class
class CRC {
  string input, divisor, divident, result;
  int len_divident, len_gen, len_inp;
  //A cyclic redundancy check (CRC) is an error-detecting code commonly used in digital networks and storage devices to detect accidental changes to raw data.
  public: 

    //Function for doing XOR
    string fun_xor(string a, string b) {
      string result = "";
      if(a[0] == '0') {
        return a.substr(1);
      } else {
        for(int i=0;i<len_gen;i++) {
          result = result + (a[i] == b[i] ? '0' : '1');
        }
        return result.substr(1);
      }
    }



    //Function to get Modulo
    void modulo_div() {
      string temp_div = divisor;
      string temp_divident = divident.substr(0, len_gen);
      int j = len_gen;
      while(j < len_divident) {
        temp_divident = fun_xor(temp_divident, temp_div);
        temp_divident = temp_divident + divident[j];
        j++;
      }
      result = input + fun_xor(temp_divident, temp_div);
    }



    //Function to GetData From the User
    void getdata() {
      cout<<"Enter Source Input: "<<endl;
      cin>>input;
      cout<<"Enter Coefficients of generator polynomial: "<<endl;
      cin>>divisor;

      len_gen = divisor.length();
      len_inp = input.length();
      divident = input;
      int r = len_gen-1;

      for(int i=0;i<r;i++) {
        divident = divident + '0';
      }
      len_divident = divident.length();
      modulo_div();
    }



    //function showing SenderSide-Info
    void sender_side() {
      cout<<"Input: "<<input<<endl;
      cout<<"Polynomial: "<<divisor<<endl;
      cout<<"Divident: "<<divident<<endl;
      cout<<"Data to send: "<<result<<endl;
    }



    //function showing receiverSide-Info
    void receiver_side() {
      string data_rec;
      cout<<"Enter Data Received: "<<endl;
      cin>>data_rec;

      string temp_div =  divisor;
      string temp_divident = data_rec.substr(0, len_gen);
      int j = len_gen;
      while(j < data_rec.length()) {
        temp_divident = fun_xor(temp_divident, temp_div);
        temp_divident = temp_divident + data_rec[j];
        j++;
      }
      string error = fun_xor(temp_divident, temp_div);
      cout<<"Remainder is: "<<error<<endl;

      bool flag = 0;
      for(int i=0;i<len_gen-1;i++) {
        if(error[i] == '1') {
          flag = 1;
          break;
        }
      }
      if(flag == 0) {
        cout<<"Correct Data Received Without Any Error" <<endl;
      } else {
        cout<<"Data Received Contain Some Error"<<endl;
      }
    }
};




//Creating DEVICE-class
class Device
{
    public:
        Device();
        string data;
        int MACaddress;
        void setMACaddress(int);
        void setData(string);
};
Device::Device()
{
    //Constructor
}
void Device::setMACaddress(int MAC)
{
   MACaddress=MAC;
}
void Device::setData(string dat)
{
    data=dat;
}



//Creating HUB-Class
class Hub
{
    public:
        Hub();
        string data2;
        int macAdd;
        void store(string dev, string src, int mac);
        void hub2dev(string dev,string src, int macAdd);
};

Hub::Hub()
{
    macAdd = 0;
    data2 = "0";
}

void Hub::store(string SD_Data, string sourceDevice, int devMACaddress)
{
  data2 = SD_Data;
	macAdd = devMACaddress;
	hub2dev(data2, sourceDevice, macAdd);
}

//Naming Devices and Hub
Device dev1,dev2,dev3,dev4,dev5;
Hub hb1;



void deviceInfo() {
  //here, I am initializing Devices.
  dev1.setData("0");
  dev2.setData("0");
  dev3.setData("0");
  dev4.setData("0");
  dev5.setData("0");
  dev1.setMACaddress(00-15-9-2-99-3);
  dev2.setMACaddress(00-15-8-3-99-6);
  dev3.setMACaddress(00-15-7-4-99-9);
  dev4.setMACaddress(00-15-6-5-99-2);
  dev5.setMACaddress(00-15-5-6-99-4);
}



//HUB2DEVICE-Connection
void Hub::hub2dev(string data2,string sourceDevice, int macAdd)
{
	if(dev1.MACaddress==macAdd && dev1.data==data2 && sourceDevice!="dev1") {
    cout<<" dev1 Accepted the Data and the Received data is: "<<data2<<endl;
  }
	else {
    if(sourceDevice!="dev1") {
      cout<<" Data doesn't belong to  dev1"<<endl;
    }
  }
	if(dev2.MACaddress==macAdd && dev2.data==data2 && sourceDevice!="dev2") {
    cout<<" dev2 Accepted the Data and the Received data is: "<<data2<<endl;
  }
	else {
    if(sourceDevice!="dev2") {
      cout<<" Data doesn't belong to dev2"<<endl;
    }
  }
	if(dev3.MACaddress==macAdd && dev3.data==data2 && sourceDevice!="dev3") {
    cout<<" dev3 Accepted the Data and the Received data is: "<<data2<<endl;
  }
	else {
    if(sourceDevice!="dev3") {
      cout<<" Data doesn't belong to dev3"<<endl;
    }
  }
	if(dev4.MACaddress==macAdd && dev4.data==data2 && sourceDevice!="dev4") {
    cout<<" dev4 Accepted the Data and the Received data is: "<<data2<<endl;
  }
	else {
    if(sourceDevice!="dev4") {
      cout<<" Data doesn't belong to dev4"<<endl;
    }
  }
	if(dev5.MACaddress==macAdd && dev5.data==data2 && sourceDevice!="dev5") {
    cout<<" dev5 Accepted the Data and the Received data is: "<<data2<<endl;
  }
	else {
    if(sourceDevice!="dev5") {
      cout<<" Data doesn't belong to dev5"<<endl;
    }
  }
	cout<<endl;
}



//MainFunction
int main() {
  int c1, c2;
  string SD_Data;
  string sourceDevice, destinationDevice;
  cout<<"What's your Choice?  :"<<endl;
  cout<<"1: PhysicalLayer  2: DataLinkLayer " <<endl;
  cin>>c1;
  switch(c1) {
    case 1: {
      //Implementation of PhysicalLayer
      deviceInfo();
      cout<<"Devices we have: dev1, dev2, dev3, dev4, dev5"<<endl;
      cout<<"Choose SourceDevice: "<<endl;
      cin>>sourceDevice;//Taking sourceDevice as Input
      //sourceDevice-Validation
      if(sourceDevice!="dev1" && sourceDevice!="dev2" && sourceDevice!="dev3" && sourceDevice!="dev4" && sourceDevice!="dev5") {
        cout<<"Invalid SourceDevice "<<endl;
        break;
      }

      cout<<"Choose DestinationDevice: "<<endl;
      cin>>destinationDevice;//Taking DestinationDevice as Input
      //destinationDevice-Validation
      if(destinationDevice!="dev1" && destinationDevice!="dev2" && destinationDevice!="dev3" && destinationDevice!="dev4" && destinationDevice!="dev5") {
        cout<<"Invalid destinationDevice "<<endl;
        break;
      }

      cout<<"SourceDevice Data Input for transmission: "<<endl;
      cin>>SD_Data;//Taking sourceDeviceData as Input
      //sourceDeviceData Validation
      for(int i=0;i<SD_Data.size();i++) {
        if(SD_Data[i]!='0' && SD_Data[i]!='1') {
          cout<<"Invalid sourceDeviceData "<<endl;
          break;
        }
      }

      //assigning sourceDeviceData to sourceDevice
      if(sourceDevice=="dev1") {
        dev1.setData(SD_Data);
      }
      if(sourceDevice=="dev2") {
        dev2.setData(SD_Data);
      }
      if(sourceDevice=="dev3") {
        dev3.setData(SD_Data);
      }
      if(sourceDevice=="dev4") {
        dev4.setData(SD_Data);
      }
      if(sourceDevice=="dev5") {
        dev5.setData(SD_Data);
      }

      //DevicesData in the initialState
		cout<<"DevicesData before Transmission: "<<endl;
    cout<<"dev1 data before Transmission:    "<<dev1.data<<endl;
		cout<<"dev2 data before Transmission:    "<<dev2.data<<endl;
		cout<<"dev3 data before Transmission:    "<<dev3.data<<endl;
		cout<<"dev4 data before Transmission:    "<<dev4.data<<endl;
		cout<<"dev5 data before Transmission:    "<<dev5.data<<endl; 

    //Choose for DEDICATED-NETWORK-CONNECTION OR STAR-TOPOLOGY-CONNECTION
    cout<<"Choose your Choice: "<<endl;
    cout<<"1: StarTopologyConnection 2: DedicatedNetworkConnection "<<endl;
    cin>>c2;
      switch(c2) {
        case 1: {
          //STAR-TOPOLOGY-CONNECTION
          if(destinationDevice=="dev1")
          {
            dev1.setData(SD_Data);
            hb1.store(SD_Data, sourceDevice, dev1.MACaddress);
          }
          if(destinationDevice=="dev2")
          {
            dev2.setData(SD_Data);
            hb1.store(SD_Data, sourceDevice, dev2.MACaddress);
          }
	        if(destinationDevice=="dev3")
    	    {
	        	dev3.setData(SD_Data);
        		hb1.store(SD_Data, sourceDevice, dev3.MACaddress);
          }
          if(destinationDevice=="dev4")
          {
            dev4.setData(SD_Data);
            hb1.store(SD_Data, sourceDevice, dev4.MACaddress);
          }
          if(destinationDevice=="dev5")
          {
            dev5.setData(SD_Data);
            hb1.store(SD_Data, sourceDevice, dev5.MACaddress);
          }
          break;
        }
        case 2: {
          //DEDICATED-NETWORK-CONNECTION
          if(destinationDevice=="dev1"||destinationDevice=="dev2"||destinationDevice=="dev3"||destinationDevice=="dev4"||destinationDevice=="dev5")
        {

            //sourceDevice-transfer
            if(sourceDevice=="dev1")
            {
                    dev1.setData("0");
            }
            if(sourceDevice=="dev2")
            {
                    dev2.setData("0");
            }
            if(sourceDevice=="dev3")
            {
                    dev3.setData("0");
            }
            if(sourceDevice=="dev4")
            {
                    dev4.setData("0");
            }
            if(sourceDevice=="dev5")
            {
                    dev5.setData("0");
            }

            //DEDICATED-CONNECTION
            if(destinationDevice=="dev1")
            {
              dev1.setData(SD_Data);
            }
            if(destinationDevice=="dev2")
            {
              dev2.setData(SD_Data);
            }
            if(destinationDevice=="dev3")
            {
              dev3.setData(SD_Data);
            }
            if(destinationDevice=="dev4")
            {
              dev4.setData(SD_Data);
            }
            if(destinationDevice=="dev5")
            {
              dev5.setData(SD_Data);
            }
            cout<<"DevicesData after Transmission: "<<endl;
            cout<<"dev1 data after Transmission:    "<<dev1.data<<endl;
            cout<<"dev2 data after Transmission:    "<<dev2.data<<endl;
            cout<<"dev3 data after Transmission:    "<<dev3.data<<endl;
            cout<<"dev4 data after Transmission:    "<<dev4.data<<endl;
            cout<<"dev5 data after Transmission:    "<<dev5.data<<endl;      	
          }
          break;
        }
        default: {
          cout<<"Invalid Choice :( "<<endl;
        }
      }
      break;
    }
    case 2: {
      //Implementation of DataLinkLayer
      int c3;
      cout<<"What's your Choice? :"<<endl;
      cout<<"1: HubSwitchHub-Configuration 2: SwitchDevice-Configuration 3: CRC"<<endl;
      cin>>c3;
      switch(c3) {
        case 1: {
          //Implementation of HubSwitchHub-Configuration
          cout<<"HubSwitchHub-Configuration is not yet completed"<<endl;
          break;
        }
        case 2: {
          //Implementation of SwitchDevice-Configuration
          int SourceDevice2,destinationDevice2,extra,TotDevices,count=1,bridge_count=0;
          string data3;
          cout<<"Switch is Created "<<endl;
          cout<<"Give total number of end devices: "<<endl;
          //Total number of end devices
          cin>>TotDevices;
          while(count) {
            cout<<"Choose source from 1,2,3: "<<endl;
            cin>>SourceDevice2;
            cout<<"Choose Destination from 1,2,3 (shouldn't be same as Source): "<<endl;
            cin>>destinationDevice2;
            cout<<"Enter Data to do transmission: "<<endl;
            cin>>data3;
            bridge_count++;
            //DataLink Part
            //SourceDevice and destinationDevice are from 1,2,3
            Device d[TotDevices];
            //first time forwards ARP request to all ports to get mac of all
            if(bridge_count == 1) {
              for(int i=0;i<TotDevices;i++) {
                d[i].setMACaddress(i+500);
              }
              clock_t start;
              double time_taken;
              start = clock();
              for(int j=0; j<TotDevices; j++){
                if (j==SourceDevice2-1) {
                  continue;
                }
                for(int i=0;i<data3.length();i++) {
                    d[destinationDevice2-1].data+=data3[i];
                        if(j==destinationDevice2-1) {
                          cout<<"Received frame number: "<<(i+1)<<" at The Destination "<<j+1<<endl;
                          cout<<"Received frame number: "<<(i+1)<<endl;
                          cout<<"The source "<<SourceDevice2<<" received the ACK"<<endl;
                        }
                        else {
                          break;
                        }
                    }
                }
              time_taken = ( clock() - start) / (double) CLOCKS_PER_SEC;
              cout<<"Total Time Taken for Transmission: "<< time_taken <<endl;
              cout<<"Broadcast domain = 1 and Collision domain = "<<TotDevices;
            }
            else {
              //now source know which port connected to which so direct transmission
	          	//look up in table and forward frame to destination
              clock_t start; 
              double time_taken;
              start = clock();
              for(int j=0; j<TotDevices; j++) {
                if(destinationDevice2 == j+1) {
                  for(int i=0;i<data3.length();i++) {
                    d[destinationDevice2-1].data+= data3[i];
                    if(j==destinationDevice2-1) {
                      cout<<"Received frame number: "<<(i+1)<<" at The Destination "<<(j+1)<<endl;
                      cout<<"The source "<<SourceDevice2<<" received the ACK "<<endl;
                    } else {
                      break;
                    }
                  }
                }
              }
              time_taken = (clock() - start ) / (double) CLOCKS_PER_SEC;
            	cout<<"Total Time Taken for Transmission: "<< time_taken <<endl;
		          cout<<"Broadcast domain = 1 and Collision domain = "<<TotDevices<<endl;
            }
            cout<<endl;
            cout<<"Enter any key greater than 0 if you want to do more transmission: "<<endl;
            cin>>extra;
            if(extra<=0) {
              count = 0;
            }
          }
          //SwitchDeviceConfigurationCompleted
          break;
        }
        case 3: {
          //A cyclic redundancy check
          CRC crc;
          crc.getdata();
          crc.sender_side();
          crc.receiver_side();
          break;
        }
      }
    }
  }
  return 0;
}