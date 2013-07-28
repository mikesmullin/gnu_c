/*
as in the javascript world,
what we are copying is less like traditional
object-oriented design pattern
and more like objects, hashes, and prototypes.
where basically all you have are objects
and all objects, even the base from which all extend,
are really hash tables.

some keys are treated specially like:
constructor
prototype
prototype.constructor

i would call it an object here, too
but its confusing
because its really not object-oriented in the
strict sense
its still very procedural
it can be made oo if you choose, but not required
etc.

there's no reason we can't treat ANSI C like this.
now i get what they meant when they suggested that
strict ooc may not be desirable.

so in my world,
all objects are called what they really are--Hashes
*/
struct Hash {
  // all are defined as void * so they can be easily overridden
  void * (* new)(int arglen, vm_list * args);
  void * (* dealloc)(void);
  void * (* length)(void);
  void * (* set)(char * key, void * val);
  void * (* get)(const int i);
};

void * Hash_new(int arglen, vm_list * args){};
void * Hash_dealloc(void){}:
void * Hash_length(void){};
void * Hash_set(char * key, void * val){};
void * Hash_get(const int i){};

static const struct Hash Hash = {
  Hash_new,
  Hash_dealloc,
  Hash_length,
  Hash_set,
  Hash_get
}



/*
now, what methods do i want to give it?
it should stay pretty light i think to avoid
blowing up memory where a lot of objects are involved
therefore it may be a good idea to keep methods
like .each out of the default object
everyone hated Prototype.js for adding that shit
by extending Object or Element directly. it should
be a choice left up to the developer, but still
entirely possible to add.
so i guess we can define them once outside of the
object?
but that isn't much different from class methods.
hmm...
well i kind of like coffee's for more than i like
ruby's .each or underscore/jQuery's .each
it feels more readable
so i'll go with that i suppose...
except a for ...loop in c wont work on these
i guess i better leave that alone
and just provide class methods
*/
//void * Hash_each;
// could still use a C for loop. see below
/*
one of the most annoying things about javascript
is that hashes cannot be ordered. so you find
yourself converting hashes to arrays of arrays
just so you can order them. thats nonsense.
our hashes (like Judy's) will be orderable,
but randomly ordered to start.
*/
//void * Hash_sort;
// bah a user could define this if they wanted
/*
therefore our hash may also have a beginning
and an end. so really in my example
arrays are hashes too
they're hashes that are ordered automatically
each time they are updated.
*/
//void * Hash_first;
//void * Hash_last;
/*
except these are unnecessary
as long as you can reference a hash by index
and get its length
thats enough.
*/
