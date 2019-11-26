from datetime import datetime

class FileManager:

	'''
		A context manager class for file operations
	'''
	def __init__(self,filename,mode):

		'''
			_filename : file to be considered
			_mode : mode of operation
			_file : file to be returned after the requested file is available in the required mode
		'''

		self._filename = filename
		self._mode = mode
		self._file = None

	def __enter__(self):

		'''
			Entry function
		'''

		self._file = open(self._filename, self._mode)
		return self._file

	def __exit__(self, exc_typr, exc_value, exc_traceback):

		'''
			Exit function
		'''

		self._file.close()

class PostcardList(FileManager):

	'''
		PostcardList class for all the postcard related operations
	'''

	def __init__(self):

		'''
			- _file: file name, eventually with the full path.
			- _postcards: list of postcards read from _file.
			- _date: is a dict where the key is the string date, and the value is a list of indices. Each index refers to the corresponding record.
			- _from: is a dict where the key is the string sender, and the value is a list of indices. Each index refers to the corresponding record.
			- _to:   is a dict where the key is the string receiver, and the value is a list of indices. Each index refers to the corresponding record.
		'''

		self._file = ""
		self._postcards = []
		self._date = {}
		self._from = {}
		self._to = {}

	def writeFile(self, filename):

		'''
			Function which writes the postcard messages to the given file
		'''

		with FileManager(filename, "w") as file:
			for postcard in self._postcards:
				file.write(postcard)

	def readFile(self, filename):

		'''
			Function which reads the postcard messages from the given file and parses the messages into date, sender and receiver respectively
		'''

		self._postcards = []
		self._file = filename
		with FileManager(filename, "r") as file:
			for line in file:
				self._postcards.append(line)
		self.parsePostcards()

	def parsePostcards(self):

		'''
			Function which parses the messages into date, sender and receiver and updates the dictionaries respectively
		'''

		for index, post in enumerate(self._postcards):
			post = post.split()
			date = datetime.strptime(post[0].replace('date:','')[:-1], "%Y-%m-%d")
			sender = post[1].replace('from:','')[:-1]
			receiver = post[2].replace('to:','')[:-1]
			if date not in self._date:
				self._date[date] = []
			if sender not in self._from:
				self._from[sender] = []
			if receiver not in self._to:
				self._to[receiver] = []
			self._date[date].append(index)
			self._from[sender].append(index)
			self._to[receiver].append(index)

	def updateFile(self, filename):

		'''
			Function which updates the file with the current postcard messages from the dictionary
		'''

		with FileManager(filename, "a") as file:
			for postcard in self._postcards:
				file.write(postcard)

	def updateLists(self, filename):

		'''
			Function which updates the postcard list in the dictionary with the current postcard messages from the given file
		'''

		self._file = filename
		with FileManager(filename, "w") as file:
			for line in file:
				self._postcards.append(line)
		self.parsePostcards()

	def getNumberOfPostcards(self):

		'''
			Function which returns the number of postcards present
		'''

		return len(self._postcards)

	def getPostcardsByDateRange(self, date_range):

		'''
			Function which filters the postcard by the given date range and returns a list of the postcards within the given date range
		'''

		postcards_sortedBy_date = []
		for date in self._date:
			if date_range[0] <= date <= date_range[1]:
				for index in self._date[date]:
					postcards_sortedBy_date.append(self._postcards[index])
		return postcards_sortedBy_date

	def getPostcardsBySender(self, sender):

		'''
			Function which filters the postcard by the sender and returns a list of the postcards from the given sender
		'''

		postcards_sortedBy_sender = []
		if sender in self._from:
			for index in self._from[sender]:
				postcards_sortedBy_sender.append(self._postcards[index])
		return postcards_sortedBy_sender

	def getPostcardsByReceiver(self, receiver):

		'''
			Function which filters the postcard by the receiver returns a list of the postcards received by the given receiver
		'''

		postcards_sortedBy_receiver = []
		if receiver in self._to:
			for index in self._to[receiver]:
				postcards_sortedBy_receiver.append(self._postcards[index])
		return postcards_sortedBy_receiver
