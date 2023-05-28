CFLAGS = -std=c++17 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

vk_demo: main.cpp
	glslc shaders/shader.vert -o shaders/vert.spv
	glslc shaders/shader.frag -o shaders/frag.spv
	clang++ $(CFLAGS) -o vk_demo main.cpp $(LDFLAGS)

.PHONY: test clean

test: vk_demo
	./vk_demo

clean:
	rm -f vk_demo
