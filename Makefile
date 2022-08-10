all: font_rendering_tool
font_rendering_tool: font_rendering_tool.o
	gcc -o font_rendering_tool font_rendering_tool.o `pkg-config --libs gtk4`
font_rendering_tool.o: font_rendering_tool.c
	gcc -c -o font_rendering_tool.o `pkg-config --cflags gtk4` font_rendering_tool.c
.Phony: clean
clean:
	rm -f font_rendering_tool font_rendering_tool.o
