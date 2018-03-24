#define OPENSTACK

#include <bits/stdc++.h>
#define MAXN 100010
#define Q 322
#define INF ~0ULL

using namespace std;

int n , m , cnt , a[ MAXN ] , tag[ MAXN ] , caocoacao[ MAXN ] , up[ MAXN ] , vis[ MAXN ];
int gandan [ MAXN ] , fa[ MAXN ] , size[ MAXN ] , son[ MAXN ] , xxxxxx[ MAXN ];
unsigned char left_bit[65536] , ssssssss[65536];
unsigned int wocaonimabis[31][ MAXN ] , f[31][65536] , lastans;

struct wocaonima
{
	unsigned long long bit[470];
	void clear()
	{
		memset( bit , 0 , sizeof( bit ) );
	}
	void operator |= ( const wocaonima & rhs )
	{
		for( register int i = 0 ; i <= 469 ; i++ )
			bit[i] |= rhs.bit[i];
	}
	void operator |= (const int x)
	{
		bit[x >> 6] |= 1ll << ( x & 63 );
	}
	inline int find( unsigned char k )
	{
		int len = 0 , v[4];
		register unsigned int x = 0;
		for( register int i = 0 ; i <= 469 ; i++ )
		{
			v[0] = bit[i] & 65535 , v[1] = ( bit[i] >> 16 ) & 65535 , v[2] = ( bit[i] >> 32 ) & 65535 , v[3] = ( bit[i] >> 48 );
			for( register char j = 0 ; j <= 3 ; j++ )
				if( v[j] == 65535 ) len += 16;
				else
				{
					//if( len + left_bit[ v[j] ] ) cerr << " " << len + left_bit[ v[j] ] << endl;
					x += wocaonimabis[k][ len + left_bit[ v[j] ] ];
					x += f[k][ v[j] ];
					len = ssssssss[ v[j] ];
				}
		}
		return x;
	}
} ans;

wocaonima BIT[Q + 5][Q + 5];
vector < int > linker[ MAXN ];

#define cur linker[x][i]

void dfs1( int x )
{
	size[x] = 1;
	for( int i = 0 ; i < linker[x].size() ; i++ )
		if( cur != fa[x] )
		{
			fa[ cur ] = x , gandan [ cur ] = gandan [x] + 1;
			dfs1( cur ) , size[x] += size[ cur ];
			if( size[ cur ] > size[ son[x] ] ) son[x] = cur;
		}
}

void dfs2( int x , int t )
{
	xxxxxx[x] = t;
	if( son[x] ) dfs2( son[x] , t );
	for( int i = 0 ; i < linker[x].size() ; i++ )
		if( cur != fa[x] && cur != son[x] )
			dfs2( cur , cur );
}

inline int lca( int a , int b )
{
	while( xxxxxx[a] != xxxxxx[b] )
	{
		if( gandan [ xxxxxx[a] ] < gandan [ xxxxxx[b] ] ) swap( a , b );
		a = fa[ xxxxxx[a] ];
	}
	return gandan [a] < gandan [b] ? a : b;
}

#undef cur

struct io
{
	char ibuf[1 << 23] , * s , obuf[1 << 20] , * t;
	int a[24];
	io() : t( obuf )
	{
		fread( s = ibuf , 1 , 1 << 23 , stdin );
	}
	~io()
	{
		fwrite( obuf , 1 , t - obuf , stdout );
	}
	inline int read()
	{
		register int u = 0;
		while( * s < 48 ) s++;
		while( * s > 32 )
			u = u * 10 + * s++ - 48;
		return u;
	}
	template < class T >
	inline void print( T u , int v )
	{
		print( u );
		* t++ = v;
	}
	template< class T >
	inline void print( register T u )
	{
		static int * q = a;
		if( !u ) * t++ = 48;
		else
		{
			if( u < 0 )
				* t++ = 45 , u *= -1;
			while( u ) * q++ = u % 10 + 48 , u /= 10;
			while( q != a )
				* t++ = * --q;
		}
	}
} ip;

#define read ip.read
#define print ip.print

inline void addedge( int x , int y )
{
	linker[x].push_back( y );
	linker[y].push_back( x );
}

int main()
{
	#ifdef OPENSTACK
		int size = 64 << 20; // 64MB
		char *p = (char*)malloc(size) + size;
		#if (defined _WIN64) or (defined __unix)
			__asm__("movq %0, %%rsp\n" :: "r"(p));
		#else
			__asm__("movl %0, %%esp\n" :: "r"(p));
		#endif
	#endif
	srand( time( 0 ) );
	for( int s = 0 ; s < 65536 ; s++ )
	{
		left_bit[s] = ssssssss[s] = 16;
		for( register int i = 0 ; i < 16 ; i++ )
			if( !( ( s >> i ) & 1 ) )
			{
				left_bit[s] = i;
				break;
			}
		for( register int i = 15 ; ~i ; i-- )
			if( !( ( s >> i ) & 1 ) )
			{
				ssssssss[s] = 15 - i;
				break;
			}
	}
	n = read() , m = read();
	for( int i = 0 ; i <= n ; i++ )
		for( register int j = wocaonimabis[0][i] = 1 ; j <= 30 ; j++ )
			wocaonimabis[0][0] = 0 , wocaonimabis[j][i] = wocaonimabis[j - 1][i] * i;
	for( int j = 0 ; j <= 30 ; j++ )
		for( int s = 0 ; s < 65536 ; s++ )
		{
			int len = 0;
			for( register int i = left_bit[s] + 1 ; i <= 15 - ssssssss[s] ; i++ )
				if( ( s >> i ) & 1 ) len++;
				else f[j][s] += wocaonimabis[j][ len ] , len = 0;
			if( len ) f[j][s] += wocaonimabis[j][ len ];
		}
	for( register int i = 1 ; i <= n ; i++ ) a[i] = read();
	for( register int i = 1 ; i < n ; i++ ) addedge( read() , read() );
	dfs1( 1 ) , dfs2( 1 , 1 );
	for( int i = 1 ; i <= min( n , Q ) ; i++ )
	{
		int pos;
		while( vis[ pos = rand() * rand() % n + 1 ] );
		vis[ pos ] = 1 , tag[i] = pos , caocoacao[ tag[i] ] = i;
	}
	for( int i = 1 ; i <= min( n , Q ) ; i++ )
	{
		int cur = tag[i];
		ans.clear();
		do
		{
			ans |= a[ cur ];
			if( cur != tag[i] && caocoacao[cur] ) 
			{
				BIT[i][ caocoacao[ cur ] ] |= ans;
				if( !up[ tag[i] ] )
					up[ tag[i] ] = cur;
			}
			cur = fa[ cur ];
		}
		while( cur );
	}
	for( int i = 1 ; i <= m ; i++ )
	{
		int cnt = read();
		ans.clear();
		for( int j = 1 ; j <= cnt ; j++ )
		{
			int x = read() ^ lastans , y = read() ^ lastans , z = lca( x , y );
			ans |= a[z];
			while( !caocoacao[x] && x != z )
			{
				ans |= a[x];
				x = fa[x];
			}
			int now = x;
			while( gandan [ up[x] ] > gandan [z] ) x = up[x];
			ans |= BIT[ caocoacao[ now ] ][ caocoacao[x] ];
			while( x != z )
			{
				ans |= a[x];
				x = fa[x];
			}
			while( !caocoacao[y] && y != z )
			{
				ans |= a[y];
				y = fa[y];
			}
			now = y;
			while( gandan [ up[y] ] > gandan [z] ) y = up[y];
			ans |= BIT[ caocoacao[ now ] ][ caocoacao[y] ];
			while( y != z )
			{
				ans |= a[y];
				y = fa[y];
			}
		}
		print( lastans = ans.find( read() ) , '\n' );
	}
	#ifdef OPENSTACK
		exit(0);
	#else
		return 0;
	#endif
	return 0;
}
