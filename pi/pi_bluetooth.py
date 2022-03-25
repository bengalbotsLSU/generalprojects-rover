# Module for bluetooth communication with external device (computer, phone, whatever)

import bluetooth #pybluez

server_socket = bluetooth.BluetoothSocket(bluetooth.RFCOMM)

server_socket.bind(("", bluetooth.PORT_ANY))
server_socket.listen(1)

uuid = "4026c1b6-04df-45c3-a7c1-291983a73a13"
bluetooth.advertise_service(server_socket, 
"BengalRover", 
service_id=uuid, 
service_classes=[uuid, bluetooth.SERIAL_PORT_CLASS], 
profiles=[bluetooth.SERIAL_PORT_PROFILE])

client_socket, client_info = server_socket.accept()
print("accepted connection from", client_info)

# Do I really want to make a small app to do basic bluetooth data