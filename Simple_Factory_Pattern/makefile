obj=main.o

app:$(obj)
	gcc -g -o $@ $^
%.o:%.c
	gcc -g -c -o $@ $<
.PHONY:
clean:
	rm -rf $(obj) app