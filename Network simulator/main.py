from Hub import *
from CRC import *
from Physical_Layer import physicalLayer
from Data_link_layer import Data_link_layer
import time
def main():
    c1 = int(input("What's your Choice?\n1: PhysicalLayer  2: DataLinkLayer\n"))

    if c1 == 1:
        physicalLayer()

    elif c1 == 2:
        Data_link_layer()
        
    else:
        print("Try Valid Choice")


if __name__ == "__main__":
    main()
