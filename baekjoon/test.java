package baekjoon;
import java.util.*;
public class test {
    public static void main(String[] args) {
        String[] s = new String[2];
        s[0] = "i 1";
        s[1] = "d 2";
        
        System.err.println(s[0]);

        // 그냥 split 할 경우, 주소가 반환됨.
        System.out.println(s[0].split(" ")[0]);

        List[] list = new List[3];
        for(int i=0;i<list.length;i++) list[i] = new ArrayList<>();
        list[0].add(1);
        list[1].add("hi");

        System.out.println(list[1]);


        //////////////////////////////////////////////////////////////
        /// hash map의 generic으로 list가 포함되는 경우
        //////////////////////////////////////////////////////////////
        HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
        map.put(1,300);
        list[0].add(map);
        map.put(2,300);
        list[1].add(map);
        map.put(3,3400);
        list[2].add(map);

        HashMap<String,List[]> hashlist = new HashMap<>();
        
        hashlist.put("test",list);

        System.err.println(hashlist.get("test")[2].get(0));

        HashMap<Integer,Integer> tmap = new HashMap<Integer,Integer>();
        //ListType이 되어서 이미 해시맵의 형태가 아님.
        //tmap = hashlist.get("test");
        System.err.println(hashlist.get("test")[0].get(1));
        System.err.println(hashlist.get("test"));

        String[][] s4 = {
            {"POOOP", "OXXOX", "OPXPX"},
            {"POOOP", "OXXOX", "OPXPX"}
        };
        String[] s5 = s4[0];
        System.out.println(s5[0].charAt(1));

    }
}
