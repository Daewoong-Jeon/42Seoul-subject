section .text
	global _ft_strcpy

_ft_strcpy:
	cmp BYTE [rsi], 0
	mov rcx, 0
	jne copy
	je end

copy:
	mov rdx, [rsi + rcx]
	mov [rdi + rcx], rdx
	inc rcx
	cmp BYTE [rsi + rcx], 0
	jne copy
	je end

end:
	mov BYTE [rdi + rcx], 0
	mov rax, rdi
	ret
