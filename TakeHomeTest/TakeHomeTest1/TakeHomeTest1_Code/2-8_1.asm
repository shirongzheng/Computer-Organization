.data
x: .word 2
y: .word 5
z: .word 0
.text 
lw $s0, x
lw $s1, z
lw $s2, y
myadd:
addi $sp, $sp, -10


# t0 = 0+x
add $t0, $s0, $s2
# t1 = b+0
add $t1, $s2, $s3
# z= t0 - t1
sub $s1, $t0, $t1
sw $s1, z