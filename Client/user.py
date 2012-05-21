import httplib, urllib


url = "localhost:8080"

def status():
	conn = httplib.HTTPConnection(url)
	conn.request("GET","/user/status")
	return conn.getresponse().read()
	
def create(id, password, name):
	params = urllib.urlencode({'id': id, 'password': password, 'name': name})
	headers = {"Content-type": "application/x-www-form-urlencoded","Accept": "text/plain"}
	conn = http.client.HTTPConnection(url)
	conn.request("POST", "/user/create", params, headers)
	response = conn.getresponse()
	return response.read()
	
def information(id, password):
	params = urllib.urlencode({'id': id, 'password': password})
	headers = {"Content-type": "application/x-www-form-urlencoded","Accept": "text/plain"}
	conn = httplib.HTTPConnection(url)
	conn.request("POST", "/user/get", params, headers)
	response = conn.getresponse()
	return response.read()
	
