#ifndef EVENT_HD
#define EVENT_HD

class EVENT{
public:
	static EVENT create( bool initialiState = false );
	///trueにされるのを待つ
	void wait() const;
	///trueにする
	void set();
	///falseにする
	void reset();
	///true?それともfalse?
	bool isSet() const;

	EVENT();
	~EVENT();
	EVENT( const EVENT& );
	operator void*() const;
	EVENT& operator=( const EVENT& );
	void release();
	bool operator==( const EVENT& ) const;
	bool operator!=( const EVENT& ) const;
private:
	class Impl;
	Impl* mImpl;
};

#endif
