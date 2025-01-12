import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        List<Citizen> citizens = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            long L = Long.parseLong(st.nextToken());
            long R = Long.parseLong(st.nextToken());
            citizens.add(new Citizen(L, R));
        }

        List<Shop> shops = new ArrayList<>();
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            long P = Long.parseLong(st.nextToken());
            int X = Integer.parseInt(st.nextToken());
            shops.add(new Shop(P, X));
        }

        citizens.sort(Comparator.comparingLong(c -> c.R));
        shops.sort(Comparator.comparingLong(s -> s.P));

        TreeSet<Long> availableShops = new TreeSet<>();
        Map<Long, Integer> shopCounts = new HashMap<>();

        for (Shop shop : shops) {
            availableShops.add(shop.P);
            shopCounts.put(shop.P, shopCounts.getOrDefault(shop.P, 0) + shop.X);
        }

        int matched = 0;
        for (Citizen citizen : citizens) {
            Long shopPrice = availableShops.ceiling(citizen.L);

            if (shopPrice != null && shopPrice <= citizen.R) {
                matched++;
                int count = shopCounts.get(shopPrice);
                if (count == 1) {
                    availableShops.remove(shopPrice);
                }
                shopCounts.put(shopPrice, count - 1);
            }
        }

        System.out.println(matched);
    }

    static class Citizen {
        long L, R;

        Citizen(long L, long R) {
            this.L = L;
            this.R = R;
        }
    }

    static class Shop {
        long P;
        int X;

        Shop(long P, int X) {
            this.P = P;
            this.X = X;
        }
    }
}
