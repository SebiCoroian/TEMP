class TreeDistanceConstruction {
	public:
	vector <int> construct(vector <int> D) {
		vector<int> V[51];
		vector<int> R;
		int N=D.size();
		int md=0,x,i,j;
		
		FOR(i,N) V[D[i]].push_back(i), md=max(md,D[i]);
		
		int cent;
		if(md%2==0) {
			cent=md/2;
			if(V[cent].size()!=1) return {};
		}
		else {
			cent=md/2+1;
			if(V[cent].size()!=2) return {};
			R.push_back(V[cent][0]);
			R.push_back(V[cent][1]);
		}
		for(i=1;i<cent;i++) if(V[i].size()) return {};
		for(x=cent+1;x<=md;x++) {
			if(V[x].size()<2) return {};
			FOR(j,V[x].size()) {
				R.push_back(V[x][j]);
				R.push_back(V[x-1][j%V[x-1].size()]);
			}
		}
		
		return R;
		
		
	}
}
