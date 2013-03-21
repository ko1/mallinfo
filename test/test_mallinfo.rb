require 'test/unit'
require 'mallinfo'

class TestMallInfo < Test::Unit::TestCase
  def check info
    keys = %w(arena ordblks smblks hblks hblkhd usmblks
              fsmblks uordblks fordblks keepcost).map{|e| e.to_sym}
    info.each{|k, v|
      assert(Symbol === keys.delete(k))
      assert(v >= 0)
      assert_equal(v.class, Fixnum)
    }
    assert_equal(keys, [])
  end

  def test_mallinfo
    info = ObjectSpace.mallinfo
    check(info)
    info2 = ObjectSpace.mallinfo(info)
    assert_equal(info.object_id, info2.object_id)
    check(info2)
  end
end
