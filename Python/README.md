# PostCardList Implementation

### Folder structure && Execution Steps

- The **exam_solution.py** contains the PostCardList Implementation

- The **exam_requests.py** contains the necessary unit tests needed to test the implementation

### Methods

- **FileManager** is a context manger class available for resource management.

	- **Methods Present**

		- **__init__** : a function which loads the filename and mode of operation.
		- **__enter__** : a function which returns the file in the requested mode.
		- **__exit__** : a function which closes the file.

- **PostCardList** is a class of the PostCardList which contains the details about the **file**, **date**, **sender** and the **receiver** of the postcard

	- **Methods Present**

		- **writeFile** : a function which writes the postcard messages to the given file
		- **readFile** : a function which reads the postcard messages from the given file and parses the messages into date, sender and receiver respectively
		- **parsePostcards** : a function which parses the messages into date, sender and receiver and updates the dictionaries respectively
		- **updateFile** : a function which updates the file with the current postcard messages from the dictionary
		- **updateLists** : a function which updates the postcard list in the dictionary with the current postcard messages from the given file
		- **getNumberOfPostcards** : a function which filters the postcard by the given date range and returns a list of the postcards within the given date range
		- **getPostcardsBySender** : a function which filters the postcard by the sender and returns a list of the postcards from the given sender
		- **getPostcardsByReceiver** : a function which filters the postcard by the receiver returns a list of the postcards received by the given receiver

- **unittest** module is used to perform automated unit testing which is also referred to as **PyUnit**
