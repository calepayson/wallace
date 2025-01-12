import socket

# Create a socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Bind to localhost and port 12345
sock.bind(('127.0.0.1', 12345))

# Start listening
sock.listen(1)

# Accept a connection and receive data
conn, addr = sock.accept()
data = conn.recv(1024)  # Receive up to 1024 bytes
print("Received:", data)

# Clean up
conn.close()
sock.close()

