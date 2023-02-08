To Set static ip:
open net plan and statically set the ip address and change dchp4 to no,gateways,addresses which you want to enter then netplan apply.

Commands: 
1) ls /etc/netplan
2) sudo nano /etc/netplan/ 01-network-manager-all.yaml
3) sudo netplan try
4) sudo netplan apply
5) ip a

And To set dynamic ip:
open net plan and statically set the ip address and change dchp4 to yes then apply the netplan apply.

Commands:
1) ls /etc/netplan
2) sudo nano /etc/netplan/ 01-network-manager-all.yaml
3) sudo netplan try
4) sudo netplan apply
5) ip a
6) sudo systemctl restart NetworkManager.service (to restart network manager)

![Screenshot from 2023-02-08 10-49-48](https://user-images.githubusercontent.com/94800480/217448050-f3c811a7-cf31-4021-950f-19ecdf539858.png)
![Screenshot from 2023-02-08 10-51-11](https://user-images.githubusercontent.com/94800480/217448207-4e10b5bf-6048-41f5-b209-41e2fa95d860.png)
![Screenshot from 2023-02-08 10-51-46](https://user-images.githubusercontent.com/94800480/217448212-5d9f2b29-4f5d-4a2a-a6f3-caaac5b1e5a7.png)
![Screenshot from 2023-02-08 10-54-06](https://user-images.githubusercontent.com/94800480/217448218-27a50e27-0449-486c-acde-6d6273e781c7.png)
![Screenshot from 2023-02-08 10-55-26](https://user-images.githubusercontent.com/94800480/217448222-da6bacf3-6a38-4a87-952e-6d28e31d569b.png)
![Screenshot from 2023-02-08 10-57-30](https://user-images.githubusercontent.com/94800480/217448225-4166950e-3d25-4e3e-814e-72992ba2bdaf.png)

Installing samba:

Step 1: Install Samba. starting by udating and upgrading.

Step 2: Create a Shared Directory.

Step 3: Configure Samba's Global Options. Browsing/Identification. Networking.

Step 4: Set Up a User Account.

Step 5: Configure Samba Share Directory Settings.

Step 6: Update the Firewall Rules.

Step 7: Connect to the Shared Directory.

![WhatsApp Image 2023-02-08 at 11 36 34 PM](https://user-images.githubusercontent.com/94800480/217626656-7b0375ce-df0d-4f60-a3eb-01ae992a1add.jpeg)
![WhatsApp Image 2023-02-08 at 11 42 08 PM](https://user-images.githubusercontent.com/94800480/217626675-3d1262ff-22df-4d56-a84f-0654e8c56626.jpeg)
![WhatsApp Image 2023-02-08 at 11 38 58 PM](https://user-images.githubusercontent.com/94800480/217626749-66037c2d-93b6-48a8-8529-9442e7e74627.jpeg)
![WhatsApp Image 2023-02-08 at 11 42 17 PM](https://user-images.githubusercontent.com/94800480/217626757-5dcf720f-bcb3-4f40-a755-e3c908ad8c87.jpeg)
![Screenshot from 2023-02-08 20-26-48](https://user-images.githubusercontent.com/94800480/217626763-f9fd4f2b-c58c-4c6f-b327-db20ecfb6e78.png)
![WhatsApp Image 2023-02-08 at 11 36 59 PM](https://user-images.githubusercontent.com/94800480/217626767-c5ed6a85-ab16-47bb-a954-b3580294f606.jpeg)
![WhatsApp Image 2023-02-08 at 11 40 16 PM](https://user-images.githubusercontent.com/94800480/217626769-77d845b7-fac1-44a5-b50e-66f0ccf046c7.jpeg)
![WhatsApp Image 2023-02-08 at 11 40 00 PM](https://user-images.githubusercontent.com/94800480/217626773-30038614-6e03-4a5e-84c7-3fb4aa8f4982.jpeg)
![WhatsApp Image 2023-02-08 at 11 40 36 PM](https://user-images.githubusercontent.com/94800480/217626777-27b8f427-48dc-4cd7-8d52-af962dfeaf61.jpeg)
![WhatsApp Image 2023-02-08 at 11 36 42 PM](https://user-images.githubusercontent.com/94800480/217626782-948df3cd-8dc6-43cb-8108-29d15219ab99.jpeg)
![Screenshot from 2023-02-08 23-28-12](https://user-images.githubusercontent.com/94800480/217626784-15ce53b0-b64c-4734-ba13-aca926b654e1.png)
![Screenshot from 2023-02-08 20-52-14](https://user-images.githubusercontent.com/94800480/217626787-49388346-c961-445d-899f-0b6e955535e2.png)
![Screenshot from 2023-02-08 20-50-49](https://user-images.githubusercontent.com/94800480/217626789-262b7302-fd5d-494d-8e77-73381c5fcc50.png)
![Screenshot from 2023-02-08 20-38-41](https://user-images.githubusercontent.com/94800480/217626794-54b96832-7637-47a9-923e-de8c7cd91234.png)
![Screenshot from 2023-02-08 20-31-19](https://user-images.githubusercontent.com/94800480/217626801-ce2b9268-8c59-4905-a8a1-1e51073c4d01.png)
![Screenshot from 2023-02-08 20-27-56](https://user-images.githubusercontent.com/94800480/217626804-a985f8d2-1090-4378-9315-371e823a710d.png)
![WhatsApp Image 2023-02-08 at 11 41 42 PM](https://user-images.githubusercontent.com/94800480/217626808-0ae686d5-56f6-437a-9be5-abe1f5ae5b3c.jpeg)
