#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H

#ifndef _BOOLEAN_H
#include <Boolean.h>
#endif

class HashTable
{
public:
    virtual ~HashTable();

    // The following must be implemented by a particular
    // implementation (subclass):
    static HashTable* create(int keyType);

    virtual void* Add(char const* key, void* value) = 0;
    // Returns the old value if different, otherwise 0
    virtual Boolean Remove(char const* key) = 0;
    virtual void* Lookup(char const* key) const = 0;
    // Returns 0 if not found
    virtual unsigned numEntries() const = 0;
    Boolean IsEmpty() const
    {
        return numEntries() == 0;
    }

    // Used to iterate through the members of the table:
    class Iterator
    {
    public:
        // The following must be implemented by a particular
        // implementation (subclass):
        static Iterator* create(HashTable const& hashTable);

        virtual ~Iterator();

        virtual void* next(char const*& key) = 0; // returns 0 if none

    protected:
        Iterator(); // abstract base class
    };

    void* RemoveNext();

    // Returns the first entry in the table.
    void* getFirst();

protected:
    HashTable(); // abstract base class
};

int const STRING_HASH_KEYS = 0;
int const ONE_WORD_HASH_KEYS = 1;

#endif
