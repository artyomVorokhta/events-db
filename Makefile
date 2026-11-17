CXX_STANDARD ?= c++17
CXXFLAGS ?= -Wall -Wextra
CONFIG ?= debug

ifeq ($(CONFIG),debug)
	mode_cxxflags := -O0 -g
else ifeq ($(CONFIG),release)
	mode_cxxflags := -O2
else
	$(error Unknown CONFIG: $(CONFIG))
endif

project_name := events_db

src_dir := src
build_root := build
build_dir := $(build_root)/$(CONFIG)
obj_dir := $(build_dir)/obj
program := $(build_dir)/bin/$(project_name)

srcs := $(shell find $(src_dir) -type f -name '*.cpp')
objs := $(patsubst $(src_dir)/%.cpp,$(obj_dir)/%.o,$(srcs))
deps := $(objs:.o=.d)

.PHONY: all clean

all: $(program)

clean:
	rm -rf $(build_root)

$(program) : $(objs)
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(obj_dir)/%.o: $(src_dir)/%.cpp
	mkdir -p $(dir $@)
	$(CXX) -std=$(CXX_STANDARD) $(mode_cxxflags) $(CXXFLAGS) -MMD -MP -c $< -o $@

-include $(deps)
