	.name "live"
	.comment "alive"

	sti r1,%:live,%1
	ld %0,r2
live:
	live %42
	zjmp %:live
