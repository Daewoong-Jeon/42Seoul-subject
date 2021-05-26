section .text
	global _ft_strdup

extern _malloc

_ft_strdup:
	jmp ft_strlen

ft_strlen:
	mov rax, 0
	jmp count

count:
	cmp BYTE [rdi + rax], 0
	je ft_malloc
	inc rax
	jmp count

ft_malloc:
	push rdi
	;mov rsi, rdi
	inc rax
	mov rdi, rax
	call _malloc
	cmp rax, 0
	je return
	pop rdi
	mov rcx, 0
	cmp BYTE [rdi + rcx], 0
	je end
	jmp input

input:
	mov rdx, [rdi + rcx]
	mov [rax + rcx], rdx
	inc rcx
	cmp BYTE [rdi + rcx], 0
	je end
	jmp input

end:
	mov BYTE [rax + rcx], 0
	jmp return

return:
	ret
