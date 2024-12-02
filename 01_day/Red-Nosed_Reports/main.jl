
fp = "input.txt"
l = readlines(fp)
dt = [parse.(Int, split(line)) for line in l]

# Printing data
# println("Data read into array:")
# println(dt)

function row_safe(row::Vector{Int64})::Bool
    dif = diff(row)

    if any(abs(d) < 1 || abs(d) > 3 for d in dif)
        return false
    end

    if all(dif .> 0) || all(dif .< 0)
        return true
    else
        return false
    end
end

function part_two(row::Vector{Int64})::Bool
    if row_safe(row)
        return true
    end

    for i in 1:length(row)
        reduced_row = vcat(row[1:i-1], row[i+1:end])
        if row_safe(reduced_row)
            return true
        end
    end
    return false
end


# Counting truers
sa_cx = count(row_safe(row) for row in dt)
sa_pt2_cx = count(part_two(row) for row in dt)

println("Part One: ", sa_cx)
println("Part Two: ", sa_pt2_cx)
