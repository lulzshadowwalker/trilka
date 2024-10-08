# Alternative GNU Make workspace makefile autogenerated by Premake

ifndef config
  config=debug
endif

ifndef verbose
  SILENT = @
endif

ifeq ($(config),debug)
  Trilka_config = debug
  Sandbox_config = debug

else ifeq ($(config),release)
  Trilka_config = release
  Sandbox_config = release

else ifeq ($(config),dist)
  Trilka_config = dist
  Sandbox_config = dist

else
  $(error "invalid configuration $(config)")
endif

PROJECTS := Trilka Sandbox

.PHONY: all clean help $(PROJECTS) 

all: $(PROJECTS)

Trilka:
ifneq (,$(Trilka_config))
	@echo "==== Building Trilka ($(Trilka_config)) ===="
	@${MAKE} --no-print-directory -C Trilka -f Makefile config=$(Trilka_config)
endif

Sandbox: Trilka
ifneq (,$(Sandbox_config))
	@echo "==== Building Sandbox ($(Sandbox_config)) ===="
	@${MAKE} --no-print-directory -C Sandbox -f Makefile config=$(Sandbox_config)
endif

clean:
	@${MAKE} --no-print-directory -C Trilka -f Makefile clean
	@${MAKE} --no-print-directory -C Sandbox -f Makefile clean

help:
	@echo "Usage: make [config=name] [target]"
	@echo ""
	@echo "CONFIGURATIONS:"
	@echo "  debug"
	@echo "  release"
	@echo "  dist"
	@echo ""
	@echo "TARGETS:"
	@echo "   all (default)"
	@echo "   clean"
	@echo "   Trilka"
	@echo "   Sandbox"
	@echo ""
	@echo "For more information, see https://github.com/premake/premake-core/wiki"