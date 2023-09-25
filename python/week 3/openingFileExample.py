# a simple file writer object
 
class MessageWriter(object):
    def __init__(self, file_name):
        print(1)
        self.file_name = file_name
     
    def __enter__(self):
        self.file = open(self.file_name, "r+")
        print(2)
        return self.file
 
    def __exit__(self, *args):
        print(3)
        self.file.close()
 
# using with statement with MessageWriter
 
with MessageWriter('my_file.txt') as xfile:
    print("HERE")
    xfile.write('hello world')
