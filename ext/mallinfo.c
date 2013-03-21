/**********************************************************************

  mallinfo.c - get mallinfo(), "Statistics for Memory Allocation with malloc"

  $Author$
  created at: Thu Mar 21 13:52:55 2013

  All the files in this distribution are covered under the Ruby's
  license (see the file COPYING).

**********************************************************************/

#include <ruby/ruby.h>
#include <malloc.h>

static int
set_zero_i(st_data_t key, st_data_t val, st_data_t arg)
{
    VALUE k = (VALUE)key;
    VALUE hash = (VALUE)arg;
    rb_hash_aset(hash, k, INT2FIX(0));
    return ST_CONTINUE;
}

/*
 * ObjectSpace.mallinfo() -> hash
 *
 * Returns mallinfo() result in Hash. See detail
 * mallinfo(3).
 *
 */
static VALUE
mallinfo_s(int argc, VALUE *argv, VALUE os)
{
    struct mallinfo info;
    VALUE hash;

    if (rb_scan_args(argc, argv, "01", &hash) == 1) {
	if (!RB_TYPE_P(hash, T_HASH))
	  rb_raise(rb_eTypeError, "non-hash given");
    }

    info = mallinfo();

    if (hash == Qnil) {
	hash = rb_hash_new();
    }
    else if (!RHASH_EMPTY_P(hash)) {
	st_foreach(RHASH_TBL(hash), set_zero_i, hash);
    }

#define SET(attr) rb_hash_aset(hash, ID2SYM(rb_intern(#attr)), INT2NUM(info.attr));
    SET(arena);
    SET(ordblks);
    SET(smblks);
    SET(hblks);
    SET(hblkhd);
    SET(usmblks);
    SET(fsmblks);
    SET(uordblks);
    SET(fordblks);
    SET(keepcost);
#undef SET

    return hash;
}

void
Init_mallinfo(void)
{
    VALUE rb_mObjSpace = rb_const_get(rb_cObject, rb_intern("ObjectSpace"));

    rb_define_module_function(rb_mObjSpace, "mallinfo", mallinfo_s, -1);
}


