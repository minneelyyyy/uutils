
.global sys_write
sys_write:
	mov $4, %eax
	int $0x80
	ret

.global sys_exit
sys_exit:
	mov $1, %eax
	int $0x80

