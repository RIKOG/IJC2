LC_ALL=cs_CZ.utf8

CFLAGS =-std=c99 -pedantic -Wall -Wextra
COMPILER = gcc

all: tail wordcount wordcount-dynamic
static: wordcount
dynamic: wordcount-dynamic

wordcount: htab.h wordcount.c io.c io.h libhtab.a	
	ranlib libhtab.a
	$(COMPILER) $(CFLAGS) -static wordcount.c io.c -L. -lhtab -o $@

wordcount-dynamic: htab.h wordcount.c io.c io.h libhtab.so
	$(COMPILER) $(CFLAGS) wordcount.c io.c -L. -lhtab -o $@

tail: tail.o
	$(COMPILER) $(CFLAGS) $^ -o $@

tail.o: tail.c
	$(COMPILER) $(CFLAGS) -c $^

# run: primes primes-i
#	./primes && ./primes-i

.PHONY : clean clean_o
clean:
	rm tail wordcount wordcount-dynamic *.a *.so *.o

htab_size.o: htab_size.c htab_private.h
	$(COMPILER) $(CFLAGS) -c $<
htab_move.o: htab_move.c htab_private.h
	$(COMPILER) $(CFLAGS) -c $<
htab_lookup_add.o: htab_lookup_add.c htab_private.h
	$(COMPILER) $(CFLAGS) -c $<
htab_init.o: htab_init.c htab_private.h
	$(COMPILER) $(CFLAGS) -c $<
htab_hash_function.o: htab_hash_function.c htab_private.h
	$(COMPILER) $(CFLAGS) -c $<
htab_free.o: htab_free.c htab_private.h
	$(COMPILER) $(CFLAGS) -c $< 
htab_for_each.o: htab_for_each.c htab_private.h
	$(COMPILER) $(CFLAGS) -c $<
htab_find.o: htab_find.c htab_private.h
	$(COMPILER) $(CFLAGS) -c $<
htab_erase.o: htab_erase.c htab_private.h
	$(COMPILER) $(CFLAGS) -c $<
htab_clear.o: htab_clear.c htab_private.h
	$(COMPILER) $(CFLAGS) -c $<
htab_bucket_count.o: htab_bucket_count.c htab_private.h
	$(COMPILER) $(CFLAGS) -c $<

htab_size-d.o: htab_size.c htab_private.h
	$(COMPILER) $(CFLAGS) -fPIC -c $< -o $@
htab_move-d.o: htab_move.c htab_private.h
	$(COMPILER) $(CFLAGS) -fPIC -c $< -o $@
htab_lookup_add-d.o: htab_lookup_add.c htab_private.h
	$(COMPILER) $(CFLAGS) -fPIC -c $< -o $@
htab_init-d.o: htab_init.c htab_private.h
	$(COMPILER) $(CFLAGS) -fPIC -c $< -o $@
htab_hash_function-d.o: htab_hash_function.c htab_private.h
	$(COMPILER) $(CFLAGS) -fPIC -c $< -o $@
htab_free-d.o: htab_free.c htab_private.h
	$(COMPILER) $(CFLAGS) -fPIC -c $< -o $@
htab_for_each-d.o: htab_for_each.c htab_private.h
	$(COMPILER) $(CFLAGS) -fPIC -c $< -o $@
htab_find-d.o: htab_find.c htab_private.h
	$(COMPILER) $(CFLAGS) -fPIC -c $< -o $@
htab_erase-d.o: htab_erase.c htab_private.h
	$(COMPILER) $(CFLAGS) -fPIC -c $< -o $@
htab_clear-d.o: htab_clear.c htab_private.h
	$(COMPILER) $(CFLAGS) -fPIC -c $< -o $@
htab_bucket_count-d.o: htab_bucket_count.c htab_private.h
	$(COMPILER) $(CFLAGS) -fPIC -c $< -o $@

libhtab.a: htab_size.o htab_move.o htab_lookup_add.o htab_init.o htab_hash_function.o htab_free.o htab_for_each.o htab_find.o htab_erase.o htab_clear.o htab_bucket_count.o
	ar rcv $@ $^

libhtab.so: htab_size-d.o htab_move-d.o htab_lookup_add-d.o htab_init-d.o htab_hash_function-d.o htab_free-d.o htab_for_each-d.o htab_find-d.o htab_erase-d.o htab_clear-d.o htab_bucket_count-d.o
	$(COMPILER) $(CFLAGS) -shared -o $@ $^
