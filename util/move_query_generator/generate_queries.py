#	Project:	PokedexC++.
#	generate_queries.py	--	Auxiliary script to generate SQL-queries.
#	Revisions:
#	2018-12-19	--	F.R. van der Meulen	--	Created.
#	2019-01-31	--	F.R. van der Meulen	--	Major functionality rework.

#	Read input file.
file = open("move_add.txt")
text = file.read()
file.close()

#	Stored sets.
movesets = []
queries = []

#	Moveset Class	--	Lines containing all moves a Pokemon learns.
class Moveset:
	#	Creates Moveset object with all moves in it.
	def __init__(self, number, level_moves, tm_moves, egg_moves, tutor_moves):
		self.number = number
		self.level_moves = level_moves
		self.tm_moves = tm_moves
		self.egg_moves = egg_moves
		self.tutor_moves = tutor_moves

	#	Prints Moveset to console.
	def to_string(self):
		moveset_string = self.number + '\n' + self.level_moves + '\n' +  self.tm_moves + '\n' +  self.egg_moves + '\n' +  self.tutor_moves
		return moveset_string

	#	Splits moveset into Queries.
	def form_queries(self):
		query = Query()

#	Query class	--	SQL-query with info for one move.
class Query:
	#	Generates query with data for level-up moves or TM moves.
	def __init__(self, number, move, type, data):
		self.querytext = "INSERT INTO pokemon_moves VALUES ('{}', '{}', '{}', '{}');".format(self.number, self.move, self.type, self.data)

	#	Generates query without data for egg moves or tutor moves.
	def __init__(self, number, move, type):
		self.querytext = "INSERT INTO pokemon_moves VALUES ('{}', '{}', '{}', NULL);".format(self.number, self.move, self.type)

	#	Returns query as a string.
	def to_string(self):
		return self.querytext

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
			movesets.append(moves)
			lines = []

for i in range(0, len(movesets)):
	print("------------[MOVESET {}]------------".format(i))
	print(movesets[i].to_string())
	print()