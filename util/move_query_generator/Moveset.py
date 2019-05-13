#	Project:	PokedexC++.
#	Moveset.py	--	Contains lines with information on all moves a Pokemon learns.
#	Revisions:
#	2019-04-24	--	F.R. van der Meulen	--	Created.

#	Imports.
import Move

class Moveset:
	#	__init__	--	Constructor for Moveset object.
	#	Parameters:
	#		number		--	Line containing pokemon number.
	#		level_moves	--	Line containing moves learned by level-up.
	#		tm_moves	--	Line containing moves learned by TM / HM.
	#		egg_moves	--	Line containing moves learned by hatching.
	#		tutor_moves	--	Line containing moves learned by a tutor.
	def __init__(self, number, level_line, tm_line, egg_line, tutor_line):
		#	Info lines.
		self.number = number
		self.level_line = level_line
		self.tm_line = tm_line
		self.egg_line = egg_line
		self.tutor_line = tutor_line

		#	Stored moves.
		self.moves = []
	#	End __init__.

	#	to_string	--	Convert Moveset object to string.
	#	Parameters:	none.
	#	Returns:	string.
	def to_string(self):
		moveset_string = self.number + '\n' + self.level_line + '\n' +  self.tm_line + '\n' +  self.egg_line + '\n' +  self.tutor_line
		return moveset_string
	#	End to_string.

	#	parse_moves	--	Splits move lines into separate moves.
	#	Parameters:	none.
	#	Returns:	List of moves.
	def parse_moves(self):
		parse_level_moves()
		#parse_tm_moves()
		#parse_egg_moves()
		#parse_tutor_moves()
	#	End parse_moves()

	#	parse_with_data	--	Parses move line with extra data.
	#	Parameters:
	#		line	--	Line with moves.
	#		type	--	Type of moves.
	#	Returns:	void.
	def parse_with_data(self, line, type):
		print()
	#	End parse_with_data().

	#	parse_without_data	--	Parses move line without extra data.
	#	Parameters:
	#		line	--	Line with moves.
	#		type	--	Type of moves.
	#	Returns:	void.
	def parse_without_data(self, line, type):
		print()
	#	End parse_without_data().