import subprocess
import os

count = 1

sprite_dir = "../res/sprites/"
sprite_test = os.listdir(sprite_dir)
print('-------------------------------')
print('---Deleting current sprites!---')
print('-------------------------------')
for item in sprite_test:
	if item.endswith(".jpg"):
		os.remove(os.path.join(sprite_dir, item))
		print('Deleted ' + str(os.path.join(sprite_dir, item)))
print()

icons_dir = "../res/icons/"
icons_test = os.listdir(icons_dir)
print('-----------------------------')
print('---Deleting current icons!---')
print('-----------------------------')
for item in icons_test:
	if item.endswith(".jpg"):
		os.remove(os.path.join(icons_dir, item))
		print('Deleted ' + str(os.path.join(icons_dir, item)))
print()


str_num = ''
print('-------------------------------')
print('---Processing Kanto Pokemon!---')
print('-------------------------------')
for pokemon in range(1, 152):
	str_num = str(pokemon)
	if pokemon < 100:
		if pokemon < 10:
			str_num = '0' + str_num
		str_num = '0' + str_num
	subprocess.call(['./wget_sprite.sh', str_num])
print()

print('-------------------------------')
print('---Processing Johto Pokemon!---')
print('-------------------------------')
for pokemon in range(152, 252):
	subprocess.call(['./wget_sprite.sh', str(pokemon)])
print()

print('-------------------------------')
print('---Processing Hoenn Pokemon!---')
print('-------------------------------')
for pokemon in range(252, 387):
	subprocess.call(['./wget_sprite.sh', str(pokemon)])
print()

print('--------------------------------')
print('---Processing Sinnoh Pokemon!---')
print('--------------------------------')
for pokemon in range(387, 495):
	subprocess.call(['./wget_sprite.sh', str(pokemon)])
print()

print('-------------------------------')
print('---Processing Unova Pokemon!---')
print('-------------------------------')
for pokemon in range(495, 650):
	subprocess.call(['./wget_sprite.sh', str(pokemon)])
print()

print('-------------------------------')
print('---Processing Kalos Pokemon!---')
print('-------------------------------')
for pokemon in range(650, 722):
	subprocess.call(['./wget_sprite.sh', str(pokemon)])
print()

print('-------------------------------')
print('---Processing Alola Pokemon!---')
print('-------------------------------')
for pokemon in range(722, 810):
	subprocess.call(['./wget_sprite.sh', str(pokemon)])
print()

print('-------------------------------')
print('-------------DONE!-------------')
print('-------------------------------')