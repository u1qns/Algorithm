#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

struct Citizen {
    long long L, R;
    Citizen(long long L, long long R) : L(L), R(R) {}
};

struct Shop {
    long long P;
    int X;
    Shop(long long P, int X) : P(P), X(X) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, X, answer = 0;
    long long L, R, P;

    vector<Citizen> citizens;
    vector<Shop> shops;

    set<long long> availableShops;
    map<long long, int> shopCounts;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> L >> R;
        citizens.push_back({L, R});
    }

    for (int i = 0; i < M; i++) {
        cin >> P >> X;
        shops.push_back({P, X});
    }

    // 시민을 R 기준으로 정렬
    sort(citizens.begin(), citizens.end(), [](const Citizen& a, const Citizen& b) {
        return a.R < b.R;
    });

    // 상점을 P 기준으로 정렬
    sort(shops.begin(), shops.end(), [](const Shop& a, const Shop& b) {
        return a.P < b.P;
    });

    for (const auto& shop : shops) {
        availableShops.insert(shop.P);
        shopCounts[shop.P] += shop.X;
    }

    for (const auto& citizen : citizens)
    {
        auto it = availableShops.lower_bound(citizen.L); // L 이상인 상점 찾기

        if (it != availableShops.end() && *it <= citizen.R) // R 이하인지 확인
        {
            long long shopPrice = *it;
            ++answer;
            if (--shopCounts[shopPrice] == 0)
                availableShops.erase(shopPrice); // 상점 제거
        }
    }

    cout << answer;

    return 0;
}