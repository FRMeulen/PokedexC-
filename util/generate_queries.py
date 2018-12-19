#	Project:	PokedexC++.
#	generate_queries.py	--	Help script written to generate SQL queries.
#	Revisions:
#	2018-12-19	--	F.R. van der Meulen	--	Created.

#	Setup.
file = open("move_add.txt")
text = file.read()
queries = []

#	Query class.
class Query:
	#	Creates a Query object with processed information.
	def __init__(self, pokenum, movename, learndata, learnmethod):
		#	Declare fields.
		self.querytext = ""
		self.pokenum = pokenum
		self.movename = movename
		self.learndata = learndata
		self.learnmethod = learnmethod
		
		#	Directly form SQL query.
		self.form()
	#END __init__

	#	Forms the SQL query from stored information.
	def form(self):
		#	Build SQL query.
		self.querytext = "INSERT INTO pokemon_moves VALUES "
		self.querytext += "('" + self.pokenum + "', "
		self.querytext += "'" + self.movename + "', "
		self.querytext += "'" + self.learnmethod + "', "
		if self.learndata == "NULL":
			self.querytext += self.learndata + ");"
		else:
			self.querytext += "'" + self.learndata + "');"
		
		#	Append query to list.
		queries.append(self.querytext)
	#END form
		
	#	DEBUG	--	Prints the SQL query in the terminal.
	def print(self):
		print(self.querytext)
	#END print

#	Instruction class.
class Instruction:
	#	Creates an Instruction object with lines from input file.
	def __init__(self, numline, levelline, tmline, eggline, tutorline):
		#	Declare fields.
		self.numline = numline
		self.levelline = levelline
		self.tmline = tmline
		self.eggline = eggline
		self.tutorline = tutorline
		
		#	Directly form query objects.
		self.form_queries()
	#END __init__

	#	DEBUG	--	Prints the stored lines in the terminal.
	def print(self):
		print("---Instruction---")
		print(self.numline)
		print(self.levelline)
		print(self.tmline)
		print(self.eggline)
		print(self.tutorline)
		print()

	#	Forms query objects from input lines.
	def form_queries(self):
		#	Store pokemon number.
		pokenum = self.numline

		#	Processing utilities.
		movename = ""
		learndata = ""
		searchmode = "move"

		#	Scan level-up moves.
		for char in self.levelline:
			#	If looking for a move name.
			if searchmode == "move":
				if char == '|':
					#	Make query.
					query = Query(pokenum, movename, learndata, "Level")
					
					#	Reset utilities.
					movename = ""
					learndata = ""
				elif char == '(':
					#	Data is contained in brackets.
					searchmode = "data"
				else:
					#	Other characters must be part of move name.
					movename += char
			#	If looking for extra data.
			elif searchmode == "data":
				if char != ')':
					#	Characters between brackets are extra data.
					learndata += char
				else:
					#	Back to move names if brackets close.
					searchmode = "move"

		#	Send in final move.
		query = Query(pokenum, movename, learndata, "Level")
		
		#	Reset utilities.
		movename = ""
		learndata = ""

		#	Repeat for TM moves.
		for char in self.tmline:
			if searchmode == "move":
				if char == '|':
					query = Query(pokenum, movename, learndata, "TM")
					movename = ""
					learndata = ""
				elif char == '(':
					searchmode = "data"
				else:
					movename += char
			elif searchmode == "data":
				if char != ')':
					learndata += char
				else:
					searchmode = "move"
		query = Query(pokenum, movename, learndata, "TM")
		movename = ""
		learndata = ""

		#	Repeat for Egg moves.
		for char in self.eggline:
			if char == '|':
				query = Query(pokenum, movename, learndata, "Egg")
				movename = ""
				learndata = ""
			else:
				movename += char
			#	Egg moves have no extra data.
		query = Query(pokenum, movename, "NULL", "Egg")
		movename = ""

		#	Repeat for Tutor moves.
		for char in self.tutorline:
			if char == '|':
				query = Query(pokenum, movename, learndata, "Tutor")
				movename = ""
				learndata = ""
			else:
				movename += char
			#	Tutor moves have no extra data.
		query = Query(pokenum, movename, "NULL", "Tutor")
		movename = ""
		print()
	#END form_queries.


#	Reader class.
class Reader:
	#	Creates a Reader object with text from source.
	def __init__(self, text):
		#	Declare fields.
		self.text = text

		#	Directly read text.
		self.read()

	#	Reads text from source to form Instruction objects.
	def read(self):
		#	Processing utilities.
		lines = []
		line = ""
		lastchar = ""

		#	Scan character by character.
		for char in self.text:
			if char != '\n':
				#	Form lines.
				line += char
			else:
				#	If '\n' appears twice.
				if lastchar == '\n':
					#	Skip empty line.
					print("Empty line skipped!")
				#	If '\n' appears once.
				else:
					#	Append line.
					lines.append(line)
					
					#	Reset line.
					line = ""

					#	If full instruction is read.
					if len(lines) == 5:
						#	Make instruction.
						instruction = Instruction(lines[0], lines[1], lines[2], lines[3], lines[4])
						
						#	Clear lines.
						lines = []
					#END len(lines)
				#END
			#END nextline check.
			
			#	Remember last char.
			lastchar = char
		#END char loop.
	#END read
				
#	Make Reader with source text.
reader = Reader(text)

#	Write SQL queries to file.
for query in queries:
	with open("output_queries.txt", "a") as outputfile:
		outputfile.write(query + '\n')