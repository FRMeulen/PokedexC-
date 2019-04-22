#	Project:	PokedexC++.
#	generate_queries.py	--	Auxiliary script to generate SQL-queries.
#	Revisions:
#	2018-12-19	--	F.R. van der Meulen	--	Created.
#	2019-01-31	--	F.R. van der Meulen	--	Major functionality rework.

#	Stored sets.
movesets = []
queries = []

#	Stored variables.
raw_text = ""

#	read_file	--	Reads file from path and returns read text.
#	Parameters:
#		filename	--	Name of file to read.
#	Returns:	string.
def read_file(filename):
	file = open(filename)
	read_text = file.read()
	file.close()
	return read_text
#	End read_file().

#	parse_movesets	--	Splits raw text into Moveset objects.
#	Parameters:
#		text	--	Raw text to parse.
#	Returns:	list of Moveset objects.
def parse_movesets(text):
	sets = []
	lines = []
	line = ""
	for char in text:
		if char != '\n':
			line += char
		else:
			if len(line) > 0:
				lines.append(line)
				line = ""
			else:
				moves = Moveset(lines[0], lines[1], lines[2], lines[3], lines[4])
				sets.append(moves)
				lines = []

	return sets
#	End parse_movesets().

#	Print all movesets.
def print_all_movesets():
	if len(movesets) == 0:
		print("NO EXISTING MOVESETS")
	else:
		for i in range(0, len(movesets)):
			print("----------[MOVESET {}]----------".format(i))
			print(movesets[i].to_string())
			print()
#	End print_all_movesets.

#	Moveset Class	--	Lines containing all moves a Pokemon learns.
class Moveset:
	#	__init__	--	Constructor for Moveset object.
	#	Parameters:
	#		number		--	Line containing pokemon number.
	#		level_moves	--	Line containing moves learned by level-up.
	#		tm_moves	--	Line containing moves learned by TM / HM.
	#		egg_moves	--	Line containing moves learned by hatching.
	#		tutor_moves	--	Line containing moves learned by a tutor.
	def __init__(self, number, level_moves, tm_moves, egg_moves, tutor_moves):
		self.number = number
		self.level_moves = level_moves
		self.tm_moves = tm_moves
		self.egg_moves = egg_moves
		self.tutor_moves = tutor_moves
	#	End __init__.

	#	to_string()	--	Convert Moveset object to string.
	#	Parameters:	none.
	#	Returns:	string.
	def to_string(self):
		moveset_string = self.number + '\n' + self.level_moves + '\n' +  self.tm_moves + '\n' +  self.egg_moves + '\n' +  self.tutor_moves
		return moveset_string
	#	End to_string.


	#	End form_queries().

#	End Moveset Class.

#	Query class	--	SQL-query with info for one move.
class Query:
	#	Generates query with data for level-up moves or TM moves.
	def __init__(self, number, move, type, data):
		self.querytext = "INSERT INTO pokemon_moves VALUES ('{}', '{}', '{}', '{}');".format(self.number, self.move, self.type, self.data)
	#	End __init__().

	#	Generates query without data for egg moves or tutor moves.
	def __init__(self, number, move, type):
		self.querytext = "INSERT INTO pokemon_moves VALUES ('{}', '{}', '{}', NULL);".format(self.number, self.move, self.type)
	#	End __init__().

	#	Returns query as a string.
	def to_string(self):
		return self.querytext
	#	End to_string().

#	End Query Class.

#	Program sequence.
raw_text = read_file("move_add.txt")
movesets = parse_movesets(raw_text)

#	Debug.
print_all_movesets()