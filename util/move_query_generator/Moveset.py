#	Project:	PokedexC++.
#	Moveset.py	--	Contains lines with information on all moves a Pokemon learns.
#	Revisions:
#	2019-04-24	--	F.R. van der Meulen	--	Created.

#	Imports.
import Query

class Moveset:
	#	__init__	--	Constructor for Moveset object.
	#	Parameters:
	#		number		--	Line containing pokemon number.
	#		level_moves	--	Line containing moves learned by level-up.
	#		tm_moves	--	Line containing moves learned by TM / HM.
	#		egg_moves	--	Line containing moves learned by hatching.
	#		tutor_moves	--	Line containing moves learned by a tutor.
	def __init__(self, number, level_line, tm_line, egg_line, tutor_line):
		self.number = number
		self.level_line = level_line
		self.tm_line = tm_line
		self.egg_line = egg_line
		self.tutor_line = tutor_line
	#	End __init__.

	#	to_string	--	Convert Moveset object to string.
	#	Parameters:	none.
	#	Returns:	string.
	def to_string(self):
		moveset_string = self.number + '\n' + self.level_moves + '\n' +  self.tm_moves + '\n' +  self.egg_moves + '\n' +  self.tutor_moves
		return moveset_string
	#	End to_string.

	#	parse_moves	--	Splits move lines into separate moves.
	#	Parameters:	none.
	#	Returns:	List of moves.
	def parse_moves(self):
		self.level_moves = []
		self.tm_moves = []
		self.egg_moves = []
		self.tutor_moves = []

		for char in self.level_line:
			do something