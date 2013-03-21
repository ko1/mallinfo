# -*- encoding: utf-8 -*-
$:.push File.expand_path("../lib", __FILE__)
require "mallinfo/version"

Gem::Specification.new do |s|
  s.name        = "mallinfo"
  s.version     = Mallinfo::VERSION
  s.authors     = ["Koichi Sasada"]
  s.email       = ["ko1@atdot.net"]
  s.homepage    = "https://github.com/ko1/mallinfo"
  s.summary     = %q{This library returns the result of mallinfo(), the statistics for Memory Allocation with malloc in libc. See details of mallinfo().}
  s.description = %q{This library returns the result of mallinfo(), the statistics for Memory Allocation with malloc in libc. See details of mallinfo().}

  s.rubyforge_project = "mallinfo"

  s.files         = `git ls-files`.split("\n")
  s.test_files    = `git ls-files -- {test,spec,features}/*`.split("\n")
  s.executables   = `git ls-files -- bin/*`.split("\n").map{ |f| File.basename(f) }
  s.require_paths = ["lib"]
end
