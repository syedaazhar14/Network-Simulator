from Hub import *
import time
def Data_link_layer():
        c3 = int(input("What's your Choice?\n1: HubSwitchHub-Configuration 2: SwitchDevice-Configuration 3: CRC\n"))
        if c3 == 1:
            print()
            print("*******************************************************")
            print("HubSwitchHub-Configuration is not yet completed")
        elif c3 == 2:
            TotDevices = int(input("Give total number of end devices:\n"))
            count = 1
            bridge_count = 0
            while count:
                SourceDevice2 = int(input("Choose source from 1, 2, 3:\n"))
                print()
                print("*******************************************************")
                destinationDevice2 = int(input("Choose Destination from 1, 2, 3 (shouldn't be same as Source):\n"))
                print()
                print("*******************************************************")
                data3 = input("Enter Data to do transmission:\n")
                print()
                print("*******************************************************")
                bridge_count += 1
                if bridge_count == 1:
                    print()
                    print("*******************************************************")
                    d = [Device() for _ in range(TotDevices)]
                    for i in range(TotDevices):
                        d[i].setMACaddress(i + 500)
                    start = time.process_time()
                    for j in range(TotDevices):
                        if j == SourceDevice2 - 1:
                            continue
                        for i in range(len(data3)):
                            d[destinationDevice2 - 1].data += data3[i]
                            if j == destinationDevice2 - 1:
                                print("Received frame number:", i + 1, "at The Destination", j + 1)
                                print("Received frame number:", i + 1)
                                print("The source", SourceDevice2, "received the ACK")
                            else:
                                break
                    time_taken = time.process_time() - start
                    print()
                    print("*******************************************************")
                    print("Total Time Taken for Transmission:", time_taken)
                    print("Broadcast domain = 1 and Collision domain =", TotDevices)
                else:
                    start = time.process_time()
                    for j in range(TotDevices):
                        if destinationDevice2 == j + 1:
                            for i in range(len(data3)):
                                d[destinationDevice2 - 1].data += data3[i]
                                if j == destinationDevice2 - 1:
                                    print("Received frame number:", i + 1, "at The Destination", j + 1)
                                    print("The source", SourceDevice2, "received the ACK")
                                else:
                                    break
                    time_taken = time.process_time() - start
                    print("Total Time Taken for Transmission:", time_taken)
                    print("Broadcast domain = 1 and Collision domain =", TotDevices)
                extra = int(input("Enter 1 to continue else exit:\n"))
                if extra == 1:
                    count = 1
                else:
                    count = 0
        