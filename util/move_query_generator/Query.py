#	Project:	PokedexC++/util.
#	Query.py	--	Contains information for a SQL-query to add a move to a Pokemon.
#	Revisions:
#	2019-04-24	--	F.R. van der Meulen	--	Created.
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