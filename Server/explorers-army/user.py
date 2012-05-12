import webapp2

from google.appengine.ext import db

class User(db.Model):
    password = db.StringProperty()
    name = db.StringProperty()



class Create(webapp2.RequestHandler): 
    def post(self):
        user = User.get_by_key_name(self.request.get("id"))
        if user == None:
            
            user = User(key_name = self.request.get("id"))
            user.name = self.request.get("name")
            user.password = self.request.get("password")
            
            user.put()
        
            self.response.out.write("0\nsuccess")
        else:
            self.response.out.write("1\nuser id already in use")
            
class GetInformation(webapp2.RequestHandler):
    def post(self):
        user = User.get_by_key_name(self.request.get("id"))
        if user != None:
            if user.password == self.request.get("password"):
                self.response.out.write("0\n" + user.name + "\n")
            else:
                self.response.out.write("1\nwrong password\n")
        else:
            self.response.out.write("1\nno user found")

class Status(webapp2.RequestHandler):
	def get(self):
		self.response.out.write("Online")
        

        

app = webapp2.WSGIApplication([("/user/create", Create),
                              ("/user/get", GetInformation),
							  ("/user/status", Status)],
                              debug=True)
