#!/bin/bash

valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./main
