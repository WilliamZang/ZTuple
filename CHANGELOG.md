# Changelog
All notable changes to this project will be documented in this file.

## [1.2.0] - 2017-09-27

### Added

- you can create a new tuple with +[ZTupleBase tupleWithCount:]

### Removed

- remove _Pods.xcodeproj soft link file for some project which doesn't suppot it

## [1.1.0] - 2017-09-12

### Added

- you can get count using '- (NSUInteger)count'
- take some items and drop some items to get a new tuple
- extend item
- join two tuples
- convert a tuple to an array or convert an array to a tuple
- support tvOS and watchOS

### Removed

- no more dependent 'libextobjc'

### Fixed

- isEqual is correct now
- some typing error

## [1.0.0] - 2017-08-18

## Added

- ZTuple macro to get a tuple
- using ordinal number properties to access item
- using subscripts to access items
- using for-in to access itmes
- support NSCopy protocol
