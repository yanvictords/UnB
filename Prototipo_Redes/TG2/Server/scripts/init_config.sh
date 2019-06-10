#Adapt to the correspondent proxy values

sudo ip route add server_ip via proxy_ip
sudo route del -net 192.168.25.0/24
sudo route del default gw 192.168.25.1
sudo /etc/init.d/networking restart
