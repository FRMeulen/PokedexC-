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
		
		#	Parsed move lists.
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
		#	Temp variable.
		mode = "move"
		move_name = ""
		data = ""

		#	Parse level-up moves.
		for char in self.level_line:
			if mode == "move" and char == '(':
				mode = "data"
			elif mode == "data" and char != ")":
				data += char
			elif mode == "data" and char == ')':
				mode = "move"
			elif char == '|':
				print("level", move_name, data)
				move = Move.Move("level", move_name, data)
				self.moves.append(move)
				move_name = ""
				data = ""
			else:
				move_name += char

		#	Submit final move.
		print("level", move_name, data)
		move = Move.Move("level", move_name, data)
		self.moves.append(move)
		move_name = ""
		data = ""

		#	Parse TM/HM moves.
		for char in self.tm_line:
			if mode == "move" and char == '(':
				mode = "data"
			elif mode == "data" and char != ")":
				data += char
			elif mode == "data" and char == ')':
				mode = "move"
			elif char == '|':
				move = Move.Move("tm", move_name, data)
				self.moves.append(move)
				move_name = ""
				data = ""
			else:
				move_name += char

		#	Submit final move.
		print("level", move_name, data)
		move = Move.Move("level", move_name, data)
		self.moves.append(move)
		move_name = ""
		data = ""

		#	Parse egg moves.
		for char in self.egg_line:
			if char != '|':
				move_name += char
			else:
				move = Move.Move("egg", move_name)
				self.moves.append(move)
				move_name = ""

		#	Submit final move.
		print("level", move_name, data)
		move = Move.Move("level", move_name, data)
		self.moves.append(move)
		move_name = ""

		#	Parse tutor moves.
		for char in self.tutor_line:
			if char != '|':
				move_name += char
			else:
				move = Move.Move("tutor", move_name)
				self.moves.append(move)
				move_name = ""

		#	Submit final move.
		print("level", move_name, data)
		move = Move.Move("level", move_name, data)
		self.moves.append(move)
		move_name = ""

		return self.moves