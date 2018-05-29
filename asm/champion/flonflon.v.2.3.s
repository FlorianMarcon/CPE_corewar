#
# flonflon for corewar
#
# Florian Marcon
#
#
#
.name "flonflon V2.3"
.comment "you are dead"

	sti r1,%:live,%1
	ld %400,r3
	ld %1,r4
	ld %400,r5
	ld %0,r2
	fork %:live
	fork %:defense

loop:
	fork %:live
	fork %:attack
	fork %:loop
	zjmp %:loop

relive:
	live %42
	fork %:live
	zjmp %:relive

live:
	live %42
	zjmp %:live

less_hard_write:
	st r1,r5
	add r5,r4,r5
	add r5,r4,r5
	zjmp %:less_hard_write

hard_write:
	st r1,r3
	add r4,r3,r3
	add r4,r3,r3
	zjmp %:hard_write

attack:
	fork %:hard_write
	fork %:less_hard_write
	zjmp %:attack

defense:
	st r1,-100
	st r1,-100
	st r1,-100
	st r1,-100
	st r1,-100
	st r1,-100
	st r1,-100
	st r1,-100
	st r1,-100
	st r1,-100
	st r1,-100
	st r1,-100
	st r1,-100
	st r1,-100
	st r1,-100
	st r1,-100
	st r1,-100
	st r1,-100
	st r1,-100
	st r1,-100
	st r1,-100
	st r1,-100
	st r1,-100
	st r1,-100
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	st r1,2800
	fork %:attack
	zjmp %:defense
