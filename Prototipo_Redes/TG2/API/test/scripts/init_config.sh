# Configuration for Reflector/Client PC's
# Adapt to the correspondent proxy and server values

DEFAULT_ROUTER=192.168.25.1
SERVER_IP=192.168.25.6 
PROXY_IP=192.168.25.13

sudo ip route add $SERVER_IP via $PROXY_IP
sudo route del -net 192.168.25.0/24
sudo route del default gw $DEFAULT_ROUTER
sudo /etc/init.d/networking restart
