#!/usr/bin/env python3

import socket
import threading
from random import randrange
from random import choice

HOST = ''
PORT = 9099

def getTask():
	a = randrange(1, 100)
	b = randrange(1, 100)
	op = choice(['+', '-', '*', '/'])
	task = '{} {} {} = ?'.format(a, op, b)
	if op == '+': answer = a + b
	if op == '-': answer = a - b
	if op == '*': answer = a * b
	if op == '/': answer = a // b
	return task, answer

def handler(client, address):
	print('Have a new connection with', address)
	task, answer = getTask()
	client.send(bytes(task, 'utf8'))
	try:
		data = int(client.recv(10).decode('utf8'))
		print('client says:', data)
		if data == answer:
			print('Correct!')
			client.send(bytes('Correct', 'utf8'))
		else:
			print('Mistake!')
			client.send(bytes('Mistake! Answer: {}'.format(answer), 'utf8'))
	except:
		print('Somthing was wrong! =(')
		client.send(bytes('Internal server error', 'utf8'))
	finally:
		client.close()

if __name__ == '__main__':
	serv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	serv.bind((HOST, PORT))
	serv.listen(10)
	print('Server started (Ctrl+C for exit)')
	while True:
		client, address = serv.accept()
		t = threading.Thread(target=handler, args=(client, address))
		t.start()