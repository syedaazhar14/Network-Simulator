class Hub:
    def __init__(self):
        self.data2 = "0"
        self.macAdd = 0

    def store(self, SD_Data, sourceDevice, devMACaddress):
        self.data2 = SD_Data
        self.macAdd = devMACaddress
        self.hub2dev(self.data2, sourceDevice, self.macAdd)

    def hub2dev(self, data2, sourceDevice, macAdd):
        print()
        print("*******************************************************")
        if A.MACaddress == macAdd and A.data == data2 and sourceDevice != "A":
            print("A Accepted the Data and the Received data is:", data2)
        else:
            if sourceDevice != "A":
                print("Data doesn't belong to A")

        if B.MACaddress == macAdd and B.data == data2 and sourceDevice != "B":
            print("B Accepted the Data and the Received data is:", data2)
        else:
            if sourceDevice != "B":
                print("Data doesn't belong to B")

        if C.MACaddress == macAdd and C.data == data2 and sourceDevice != "C":
            print("C Accepted the Data and the Received data is:", data2)
        else:
            if sourceDevice != "C":
                print("Data doesn't belong to C")

        if D.MACaddress == macAdd and D.data == data2 and sourceDevice != "D":
            print("D Accepted the Data and the Received data is:", data2)
        else:
            if sourceDevice != "D":
                print("Data doesn't belong to D")

        if E.MACaddress == macAdd and E.data == data2 and sourceDevice != "E":
            print("E Accepted the Data and the Received data is:", data2)
        else:
            if sourceDevice != "E":
                print("Data doesn't belong to E")

        print()


class Device:
    def __init__(self):
        self.data = ""
        self.MACaddress = 0

    def setMACaddress(self, MAC):
        self.MACaddress = MAC

    def setData(self, dat):
        self.data = dat


A = Device()
B = Device()
C = Device()
D = Device()
E = Device()
hb1 = Hub()



def deviceInfo():
    # here, I am initializing Devices.

    
    A.setData("0")
    B.setData("0")
    C.setData("0")
    D.setData("0")
    E.setData("0")
    A.setMACaddress("00-15-9-2-99-3")
    B.setMACaddress("00-15-8-3-99-6")
    C.setMACaddress("00-15-7-4-99-9")
    D.setMACaddress("00-15-6-5-99-2")
    E.setMACaddress("00-15-5-6-99-4")


deviceInfo()

# HUB2DEVICE-Connection
# hb1.hub2dev("data2", "sourceDevice", "macAdd")
