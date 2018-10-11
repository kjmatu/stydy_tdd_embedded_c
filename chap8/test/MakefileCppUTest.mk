#This makefile makes all the main book code with CppUTest test harness

#Set this to @ to keep the makefile quiet
SILENCE = @

#---- Outputs ----#
COMPONENT_NAME = HomeAutomation

#--- Inputs ----#
CPP_PLATFORM = Gcc
PROJECT_HOME_DIR = .

SRC_DIRS = ../src/

TEST_SRC_DIRS = ./


INCLUDE_DIRS =\
  ./\
  $(CPPUTEST_HOME)/include\
  ../src/\

# MOCKS_SRC_DIRS =

CPPUTEST_WARNINGFLAGS = -Wall -Wswitch-default -Werror
#CPPUTEST_CFLAGS = -std=c89
CPPUTEST_CFLAGS += -Wall -Wstrict-prototypes -pedantic
# LD_LIBRARIES = -lpthread


ifeq ($(CPPUTEST_HOME),)
$(info CPPUTEST_HOME not set! See README.txt)
else
include $(CPPUTEST_HOME)/build/MakefileWorker.mk
endif
