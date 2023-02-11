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
![image](https://user-images.githubusercontent.com/94800480/218275355-7e1af86e-5503-433e-9120-b9cc6343331c.png)
![image](https://user-images.githubusercontent.com/94800480/218275362-23ea161f-3439-4fd3-a527-a140e228bbb9.png)
![image](https://user-images.githubusercontent.com/94800480/218275364-e5e79f4f-b0df-4592-adad-1df04a77c461.png)
![image](https://user-images.githubusercontent.com/94800480/218275371-21585886-90ed-469c-b851-c0042b9f480b.png)
![image](https://user-images.githubusercontent.com/94800480/218275374-e254e669-3675-4ccf-b1b4-59b3e7878470.png)
![image](https://user-images.githubusercontent.com/94800480/218275382-8f93e89a-a2b5-439d-b0ce-bf4931ae5007.png)


Step 2: Create a Shared Directory.by using mkdir -p /home/sharing command make shared directory

Step 3: Configure Samba's Global Options. Browsing/Identification. Networking.
![image](https://user-images.githubusercontent.com/94800480/218275403-83a7ef19-f21b-4961-a97a-48e7a1c57c5e.png)
![image](https://user-images.githubusercontent.com/94800480/218275406-b1324ee3-a8f8-41bd-accd-597aff2ecb14.png)
![image](https://user-images.githubusercontent.com/94800480/218275410-6ffd7765-09ea-433a-a793-988ed6833890.png)
![image](https://user-images.githubusercontent.com/94800480/218275418-de1d80dd-d1ba-4396-8bd2-a1a472d13648.png)
![image](https://user-images.githubusercontent.com/94800480/218275422-a530f58b-3270-42ee-b088-9767dbf05eab.png)

Step 4: Set Up a User Account.
![image](https://user-images.githubusercontent.com/94800480/218275429-1942137d-b1d1-4cf3-ad7c-d563c313e869.png)

Step 5: Configure Samba Share Directory Settings.Access the configuration file once again to add the previously made sharing directory.
![image](https://user-images.githubusercontent.com/94800480/218275243-3cf40567-2af6-411d-975f-59e1b7be16ff.png)

then exit the file and save changes and yhen return to the testpram output confirms that Samba is adequately configured. For a more verbose output, hit enter:
![image](https://user-images.githubusercontent.com/94800480/218275440-2d9decf5-7c1c-4335-bbb8-d36ef7e84331.png)

Step 6: Update the Firewall Rules.

![image](https://user-images.githubusercontent.com/94800480/218275444-51d1441f-c1a3-4a81-82d0-7e3b717661a2.png)

Step 7: Connect to the Shared Directory.To connect to the shared directory via GUI, access the default file manager and choose the Other Locations option. Type "smb://ip-address/sharing" into the Enter server address box and select Connect The system asks for a Username and Password. Provide the requested info and click Connect again.

![image](https://user-images.githubusercontent.com/94800480/218275452-006bf96e-44c2-44db-9063-02ce14511ee0.png)

